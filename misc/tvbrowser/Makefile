# New ports collection makefile for:	tvbrowser
# Date Created:				24 May 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	tvbrowser
PORTVERSION=	1.0
CATEGORIES=	german java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	tvbrowser
DISTNAME=	tvbrowser_v1.0_bin

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A digital tv guide

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${WRKSRC}/tvbrowser_v1.0/* ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${FILESDIR}/tvbrowser /${PREFIX}/bin/
	@${CHMOD} 755 /${PREFIX}/bin/tvbrowser

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/tvdata
	@${MKDIR} /var/tvbrowser/tvdata
	@${CHMOD} 777 /var/tvbrowser/tvdata
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
