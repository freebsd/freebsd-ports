# New ports collection makefile for: netscape-linux-6
# Date created:			8 April 2000
# Whom:				sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION=	6.2.1
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.bu.edu/pub/mirrors/ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cica.es/pub6/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ciril.fr/pub2/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/www/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cuhk.edu.hk/.3/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.darenet.dk/mirrors/ftp2.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.dei.uc.pt/.raid0/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.fh-brandenburg.de/pub/Infosystems/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.fu-berlin.de/unix/network/www/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.hu-berlin.de/pub/www/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/soft/infosystems/www/clients/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.jaist.ac.jp/net/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.kmitl.ac.th/pub/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.loxinfo.co.th/netscape/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.nsysu.edu.tw/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ruhr-uni-bochum.de/mirrors/ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.spin.ad.jp/pub/WWW/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.sunet.se/pub/www/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uit.no/pub/www/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-bielefeld.de/pub/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-c.dk/mirrors/ftp2.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.netscape.com/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-tuebingen.de/pub/mirrors/ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uniovi.es/pub/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.unipi.it/pub/mirror/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uniroma2.it/%7bC/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.upc.es/mirror/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.upc.es/pub/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ut.ee/pub/WWW/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://sunsite.cnlab-switch.ch/mirror/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://sunsite.sut.ac.jp/pub/archives/WWW/netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ntua.gr/pub/www/Netscape/netscape6/english/${PORTVERSION}/unix/linux22/xpi/
DIST_SUBDIR=	netscape6/english/${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-netscape6-${PORTVERSION}-generated-files.tar.gz

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

LATEST_LINK=	linux-netscape6
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License for Java plugin allows internal use only.  Also see license for Netscape itself"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
USE_LINUX=	yes
USE_XLIB=	yes
WRKSRC=	${WRKDIR}/netscape-installer/xpi
INSTALL_DIR=	${PREFIX}/lib/linux-netscape6
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	netscape6

.include <bsd.port.pre.mk>

pre-everything::
	${MKDIR} ${WRKSRC}/bin/plugins ${WRKSRC}/bin/chrome \
		${WRKSRC}/plugins
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
DISTFILES!=${CAT} ${.CURDIR}/work/${WRKSRC}/components.conf; ${TRUE}

do-extract:
.for i in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
.endfor
	- ${MV} ${WRKSRC}/jre-image-i386 ${WRKSRC}/bin/plugins/java2
	cd ${WRKSRC}/bin/plugins && ${LN} -s java2/plugin/i386/ns600/libjavaplugin_oji.so;

do-patch:
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/bin/chrome/user-skins.rdf ${WRKSRC}/bin/chrome/user-locales.rdf
	${CP} -p ${FILESDIR}/*rdf ${WRKSRC}/bin/chrome
	${TAR} -C ${WRKSRC}/bin -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}

do-configure:
#	- kldload linux
#	${SETENV} $DISPLAY="NONE" ${WRKSRC}/bin/netscape file:///dev/null
#	@${ECHO} \"Factory not found\" and \"cannot open display\" errors here are normal.
	${SED} -e "s;%%INSTALL_DIR%%;${INSTALL_DIR};g" \
	${FILESDIR}/start.sh >${WRKDIR}/${STARTUP_CMD}

pre-install:
	${ECHO} bin/${STARTUP_CMD} > ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO} lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/plugins; for i in `find * \! -type d | sort`; do \
		${ECHO} lib/linux-netscape6/plugins/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO} @dirrm lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm lib/linux-netscape6 >> ${PLIST}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${WRKSRC}/plugins ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
