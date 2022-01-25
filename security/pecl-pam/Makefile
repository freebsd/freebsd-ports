# Created by: wen@FreeBSD.org

PORTNAME=	pam
PORTVERSION=	2.2.4
CATEGORIES=	security pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL classes for PAM integration

LICENSE=	PHP202

USES=		php:pecl

post-patch:
# https://github.com/linux-pam/linux-pam/blob/master/libpam/include/security/_pam_macros.h
	@${CP} ${FILESDIR}/_pam_macros.h ${WRKSRC}/_pam_macros.h

.include <bsd.port.mk>
