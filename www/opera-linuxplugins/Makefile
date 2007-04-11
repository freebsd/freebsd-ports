# New ports collection makefile for:		opera-linuxplugins
# Date created:					December 17th 2006
# Whom:						Arjan van Leeuwen <freebsd-maintainer@opera.com>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www linux
MASTER_SITES=	ftp://opera.inode.at/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://ftp.ucr.ac.cr/WWW/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://www.microrpm.ca/pub/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://www.opera.mirroarrr.de/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://opera.eurenet.net/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		ftp://opera.ftp.fu-berlin.de/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		ftp://ftp.wayne.edu/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://mirrors.dedipower.com/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		http://opera.nedmirror.nl/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/&,} \
		ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/static/
PKGNAMESUFFIX=	-linuxplugins
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_DATE}.1-static-qt.i386-en

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Linux plugin support for the native Opera browser

RUN_DEPENDS=	${LOCALBASE}/share/opera/plugins/libnpp.so:${PORTSDIR}/www/opera

OPERA_VER=	9.20
OPERA_MINVER=
OPERA_REL=	final
OPERA_DATE=	20070409
OPERA_BUILD=	638

USE_BZIP2=	yes
USE_LINUX=	yes
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${DISTNAME}-${OPERA_BUILD}

NO_BUILD=	yes

PLIST_FILES=	share/opera/bin/operapluginwrapper share/opera/bin/libnpp.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/operapluginwrapper ${PREFIX}/share/opera/bin
	${CP} ${LOCALBASE}/share/opera/plugins/libnpp.so ${PREFIX}/share/opera/bin

.include <bsd.port.mk>
