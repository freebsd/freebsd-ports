# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.16.017
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	phpgroupware/phpgroupware/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web based GroupWare system

USES=		tar:bzip2
USE_PHP=	yes
WANT_PHP_MOD=	yes

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware
		cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware

.include <bsd.port.mk>
