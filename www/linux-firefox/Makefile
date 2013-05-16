# Created by: voisine
# $FreeBSD$

PORTNAME=	firefox
PORTVERSION=	21.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${PORTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

# gecko version must be exactly same
EXTRACT_DEPENDS=${NONEXISTENT}:${PORTSDIR}/www/linux-seamonkey:extract

CONFLICTS=	linux-firefox-24.* linux-firefox-1[07].*
USE_LDCONFIG=	yes
USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"

post-extract:	replace-gre
replace-gre:
	# using seamonkey gre for linux_base-f10 compat
	cd $$(${MAKE} -V WRKSRC -C ${PORTSDIR}/www/linux-seamonkey); \
		${CP} lib* dependentlibs.list ${WRKSRC}

.include <bsd.port.mk>
