# New ports collection makefile for:		opera-linuxplugins
# Date created:					December 17th 2006
# Whom:						Arjan van Leeuwen <freebsd-maintainer@opera.com>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www linux
MASTER_SITES=	ftp://opera.inode.at/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://ftp.ucr.ac.cr/WWW/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://www.microrpm.ca/pub/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://www.opera.mirroarrr.de/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://opera.eurenet.net/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		ftp://opera.ftp.fu-berlin.de/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		ftp://ftp.wayne.edu/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://mirrors.dedipower.com/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		http://opera.nedmirror.nl/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/&,} \
		ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/
PKGNAMESUFFIX=	-linuxplugins
DISTNAME=	${PORTNAME}-${OPERA_VER}.gcc3-shared-qt3.i386

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Linux plugin support for the native Opera browser

RUN_DEPENDS=	${PREFIX}/share/opera/bin/operapluginwrapper:${PORTSDIR}/www/opera

OPERA_VER=	9.61
OPERA_MINVER=
OPERA_REL=	final
OPERA_DATE=	20081017
OPERA_BUILD=	2456

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.gcc3-shared-qt3.i386

NO_BUILD=	yes

PLIST_FILES=	share/opera/bin/operapluginwrapper.linux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/lib/opera/${OPERA_VER}/operapluginwrapper ${PREFIX}/share/opera/bin/operapluginwrapper.linux

.include <bsd.port.mk>
