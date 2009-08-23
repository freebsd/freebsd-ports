# New ports collection makefile for:		opera-devel
# Date created:					April 24th 2008
# Whom:						Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_MINVER}.${OPERA_REL}
PORTEPOCH=	1
CATEGORIES=	www ipv6
#MASTER_SITES=	http://snapshot.opera.com/${MASTER_SITES_VER_PATH}/ \
#		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/${MASTER_SITES_VER_PATH} \
		ftp://opera.inode.at/${MASTER_SITES_VER_PATH} \
		http://gd.tuwien.ac.at/infosys/browsers/opera/${MASTER_SITES_VER_PATH} \
		http://ftp.ucr.ac.cr/WWW/opera/${MASTER_SITES_VER_PATH} \
		http://www.microrpm.ca/pub/opera/${MASTER_SITES_VER_PATH} \
		http://opera.eurenet.net/${MASTER_SITES_VER_PATH} \
		ftp://opera.ftp.fu-berlin.de/${MASTER_SITES_VER_PATH} \
		http://ftp.ntua.gr/pub/www/Opera/${MASTER_SITES_VER_PATH} \
		ftp://ftp.wayne.edu/opera/${MASTER_SITES_VER_PATH} \
		http://mirrors.dedipower.com/opera/${MASTER_SITES_VER_PATH} \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/${MASTER_SITES_VER_PATH} \
		http://opera.nedmirror.nl/${MASTER_SITES_VER_PATH} \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/${MASTER_SITES_VER_PATH} \
		http://mirrors.evolva.ro/opera/${MASTER_SITES_VER_PATH} \
		http://ftp.iasi.roedu.net/mirrors/ftp.opera.com/${MASTER_SITES_VER_PATH} \
		http://mirrors.xservers.ro/opera/${MASTER_SITES_VER_PATH} \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
#		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/en/${OPERA_ARCH}/${OPERA_LIB}/&,} \
#		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${OPERA_VER}.${OPERA_MINVER}-${OPERA_REL}-freebsd${OPERA_TYPE}-${OPERA_LIB}-qt3.${ARCH}

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

OPERA_VER=	10
OPERA_MINVER=	00
OPERA_REL=	b3
#OPERA_DATE=	20080422
OPERA_BUILD=	4537
MASTER_SITES_VER_PATH=	unix/freebsd/${OPERA_VER}${OPERA_MINVER}${OPERA_REL}/en/${OPERA_ARCH}/${OPERA_LIB}/
# unix/${OPERA_VER}-${OPERA_MINVER}/${OPERA_ARCH}-freebsd
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}.${OPERA_MINVER}-${OPERA_BUILD}.freebsd${OPERA_TYPE}-${OPERA_LIB}-qt3.${ARCH}
#		opera-10.00-4402.freebsd7-shared-qt3.i386

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
OPERA_LIB=	shared
.else
OPERA_TYPE=	6
OPERA_LIB=	shared
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/browser_plugins/symlinks/opera-devel|g' \
		${WRKSRC}/usr/local/share/opera/defaults/pluginpath.ini

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
	        ${MV} distinfo distinfo.$${_arch}.$${_osver}; \
	  done \
	done && \
	${CAT} distinfo.* > distinfo && ${RM} distinfo.*)

.include <bsd.port.post.mk>
