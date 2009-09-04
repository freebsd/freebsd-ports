# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www ipv6
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
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/${MASTER_SITES_VER_PATH}&,} \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
DISTNAME=	${PORTNAME}-${OPERA_VER}${OPERA_MINVER}-freebsd${OPERA_TYPE}-shared-qt3.${ARCH}

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

OPERA_VER=	10.00
OPERA_MINVER=
OPERA_REL=	final
OPERA_DATE=	20090830
OPERA_BUILD=	4585
OPERA_LIB=	shared
MASTER_SITES_VER_PATH=	unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/en/${OPERA_ARCH}/${OPERA_LIB}/
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.freebsd${OPERA_TYPE}-shared-qt3.${ARCH}

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_QT_VER=	3

MAN1=		${PORTNAME}.1

NO_BUILD=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

OPERA_ARCH=	${ARCH:S,i386,intel,}

.if ${OSVERSION} >= 700000
OPERA_TYPE=	7
.else
OPERA_TYPE=	6
.endif

#post-patch:
#	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/browser_plugins/symlinks/${PORTNAME}${PKGNAMESUFFIX}|g' \
#		${WRKSRC}/usr/local/share/opera/defaults/pluginpath.ini

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX} --docdir=${DOCSDIR} --sharedir=${DATADIR} --exec_prefix=${DATADIR}/bin --plugindir=${DATADIR}/plugins)
	@${CP} ${DATADIR}/bin/operapluginwrapper ${DATADIR}/bin/operapluginwrapper.freebsd
	@${INSTALL_SCRIPT} ${PATCHDIR}/operapluginwrapper ${DATADIR}/bin
	@${INSTALL_DATA} ${WRKSRC}/usr/local/share/opera/defaults/pluginpath.ini ${DATADIR}/defaults
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/browser_plugins/symlinks/opera|g' \
		${DATADIR}/defaults/pluginpath.ini
	@${RM} ${DATADIR}/defaults/pluginpath.ini.bak

.include <bsd.port.post.mk>
