PORTNAME=	phpgroupware
PORTVERSION=	0.9.16.017
CATEGORIES=	www
MASTER_SITES=	SF/phpgroupware/phpgroupware/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web based GroupWare system
WWW=		https://savannah.gnu.org/projects/phpgroupware/

DEPRECATED=	Abandoned upstream, decommissioned by the GNU Project, last release in 2010
EXPIRATION_DATE=	2026-11-30

USES=		php:mod tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware
		cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/data-dist/phpgroupware

.include <bsd.port.mk>
