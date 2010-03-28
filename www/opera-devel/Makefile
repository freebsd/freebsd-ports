# New ports collection makefile for:		opera-devel
# Date created:					April 24th 2008
# Whom:						Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_MINVER}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://snapshot.opera.com/unix/snapshot-${OPERA_BUILD}/${OPERA_ARCH}-freebsd/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${OPERA_VER}.${OPERA_MINVER}-${OPERA_BUILD}.freebsd${OPERA_TYPE}-${OPERA_LIB}-qt3.${ARCH}

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

OPERA_VER=	10
OPERA_MINVER=	20
OPERA_BUILD=	4744
#MASTER_SITES_VER_PATH=  unix/freebsd/${OPERA_VER}${OPERA_MINVER}${OPERA_REL}/en/${OPERA_ARCH}/${OPERA_LIB}/
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}.${OPERA_MINVER}-${OPERA_BUILD}.freebsd${OPERA_TYPE}-${OPERA_LIB}-qt3.${ARCH}
#		opera-10.20-4744.freebsd7-shared-qt3.i386

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_QT_VER=	3

MAN1=		${PORTNAME}.1

NO_BUILD=	yes

OPTIONS=	ASPELL	"Use the aspell library for spell checking"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000 && ${ARCH} == "amd64"
BROKEN=		does not fetch
.endif

OPERA_ARCH=	${ARCH:S,i386,intel,}

ONLY_FOR_ARCHS=	i386 amd64

.if ${OSVERSION} >= 700000
OPERA_TYPE=	7
OPERA_LIB=	shared
.else
OPERA_TYPE=	6
OPERA_LIB=	shared
.endif

.if ${OSVERSION} >= 800105
RUN_DEPENDS+=	compat7x-${ARCH}>=0:${PORTSDIR}/misc/compat7x
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/browser_plugins/symlinks/opera-devel|g' \
		${WRKSRC}/usr/local/share/opera/defaults/pluginpath.ini
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} '/LICENSE/s/[[:space:]]*part_install/#&/' \
		${WRKSRC}/install.sh
.endif

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX} --docdir=${DOCSDIR} --sharedir=${DATADIR} --exec_prefix=${DATADIR}/bin --plugindir=${DATADIR}/plugins)
	@${CP} ${DATADIR}/bin/operapluginwrapper ${DATADIR}/bin/operapluginwrapper.freebsd
	@${INSTALL_SCRIPT} ${PATCHDIR}/operapluginwrapper ${DATADIR}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

# maintainer
make-distinfo:
	@(for _arch in ${ONLY_FOR_ARCHS}; do \
	  for _osver in 600000 700000; do \
	    echo "generating distinfo for $${_arch} $${_osver}"; \
	      cd ${.CURDIR} && \
	        make ARCH=$${_arch} OSVERSION=$${_osver} makesum && \
	        ${MV} distinfo distinfo.$${_arch}.$${_osver}; \
	  done \
	done && \
	${CAT} distinfo.* > distinfo && ${RM} distinfo.*)

.include <bsd.port.post.mk>
