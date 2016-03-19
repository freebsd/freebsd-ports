# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.16.017
CATEGORIES=	www
MASTER_SITES=	SF/phpgroupware/phpgroupware/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web based GroupWare system

USES=		tar:bzip2
USE_PHP=	yes
WANT_PHP_MOD=	yes
IGNORE_WITH_PHP=	70

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware
		cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware

.include <bsd.port.mk>
