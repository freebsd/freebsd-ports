# New ports collection makefile for:		opera-devel
# Date created:					April 24th 2008
# Whom:						Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
CATEGORIES=	www ipv6
MASTER_SITES=	http://snapshot.opera.com/${MASTER_SITES_VER_PATH} \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${OPERA_VER}0-${OPERA_BUILD}.freebsd${OPERA_TYPE}-shared-qt3.${ARCH}

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

OPERA_VER=	10.0
OPERA_MINVER=	Alpha-1
OPERA_REL=	final
#OPERA_DATE=	20080422
OPERA_BUILD=	4102
MASTER_SITES_VER_PATH=	unix/${OPERA_VER}-${OPERA_MINVER}/${OPERA_ARCH}-freebsd/
WRKSRC=		${WRKDIR}/${DISTNAME}
#${OPERA_REL}/en/${OPERA_LIB}/

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_QT_VER=	3

NO_BUILD=	yes

OPTIONS=	ASPELL	"Use the aspell library for spell checking"	on

.include <bsd.port.pre.mk>

OPERA_ARCH=	${ARCH:S,i386,intel,}
ONLY_FOR_ARCHS=	i386 amd64
.if ${OSVERSION} >= 700000
OPERA_TYPE=	7
.elif ${OSVERSION} >= 600000
OPERA_TYPE=	6
.else
IGNORE= is only supported on FreeBSD 6.x and higher
.endif

#MASTER_SITES_VER_PATH=  unix/${OPERA_VER}-${OPERA_MINVER}/${OPERA_ARCH}-freebsd/
#WRKSRC=         ${WRKDIR}/${DISTNAME}
#DISTNAME=       ${PORTNAME}-${OPERA_VER}0-${OPERA_BUILD}.freebsd${OPERA_TYPE}-shared-qt3.${ARCH}

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX} --docdir=${DOCSDIR} --sharedir=${DATADIR} --exec_prefix=${DATADIR}/bin --plugindir=${DATADIR}/plugins)
	@${CP} ${DATADIR}/bin/operapluginwrapper ${DATADIR}/bin/operapluginwrapper.freebsd
	@${INSTALL_SCRIPT} ${PATCHDIR}/operapluginwrapper ${DATADIR}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

# maintainer
make-distinfo:
	@(for _arch in ${ONLY_FOR_ARCHS}; do \
	  for _osver in 600000 700000; do \
	    echo "generating distinfo for $${_arch} $${_osver}"; \
	      cd ${.CURDIR} && \
	        make ARCH=$${_arch} OSVERSION=$${_osver} makesum && \
	        mv distinfo distinfo.$${_arch}.$${_osver}; \
	  done \
	done && \
	cat distinfo.* > distinfo && rm distinfo.*)


.include <bsd.port.post.mk>
