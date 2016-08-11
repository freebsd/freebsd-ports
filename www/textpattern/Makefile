# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	textpattern
PORTVERSION=	4.2.0
CATEGORIES=	www
MASTER_SITES=	http://textpattern.com/file_download/56/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, flexible, elegant, easy-to-use content management system

BROKEN_powerpc64=	Does not build

USES=		cpe
NO_BUILD=	yes
NO_ARCH=	yes
WANT_PHP_WEB=	yes
USE_PHP=	mbstring xml mysql pcre

SUB_FILES=	pkg-message

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
