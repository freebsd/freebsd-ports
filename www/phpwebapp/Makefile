# Created by: ijliao
# $FreeBSD$

PORTNAME=	phpwebapp
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web application framework

USES=		shebangfix
SHEBANG_FILES=	web_app/boxes/menu/edit/xsl/test/*.sh \
		web_app/convert/convert.php \
		web_app/l10n/app/*.sh
USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PHPWEBAPP?=	${PREFIX}/www/data/web_app

do-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/www/data
	${CP} -R ${WRKSRC}/web_app/ ${STAGEDIR}${PHPWEBAPP}
	@${FIND} ${STAGEDIR}${PHPWEBAPP} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

.include <bsd.port.mk>
