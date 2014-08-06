# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	google-hangout
PORTVERSION=	0.6.3
CATEGORIES=	multimedia linux
PKGNAMEPREFIX=	linux-
MASTER_SITES=	http://dl.google.com/linux/direct/
DISTNAME=	google-talkplugin_current_i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_SUFX=	.rpm


MAINTAINER=	xmj@chaot.net
COMMENT=	Collection of video4linux support libraries (CentOS 6)

USES=	webplugin:linux
WEBPLUGIN_FILES=	libnpgoogletalk.so libnpold.so
# libnpgoogletalk.so libnpo1d.so
USE_LINUX=	yes
DIST_SUBDIR=	google/

post-extract:
	${RM} -r ${WRKDIR}/etc 
	for i in chromium-browser iceape iceweasel midbrowser mozilla xulrunner xulrunner-addons; do \
	rm -rf ${WRKDIR}/usr/lib/$$i ; \
	done

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	cd ${WRKDIR}/opt/google/talkplugin && ${COPYTREE_SHARE} . ${STAGEDIR}${WEBPLUGIN_DIR}
	cd ${WRKDIR}/usr/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
