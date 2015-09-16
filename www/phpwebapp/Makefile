# Created by: ijliao
# $FreeBSD$

PORTNAME=	phpwebapp
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web application framework

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	yes
USES=		shebangfix
WANT_PHP_WEB=	yes

SHEBANG_FILES=	web_app/boxes/menu/edit/xsl/test/*.sh \
		web_app/boxes/webnotes/db/dump.sh \
		web_app/convert/convert.php \
		web_app/l10n/*.sh \
		web_app/l10n-module/app/*.sh

post-patch:
	@${FIND} ${WRKSRC}/web_app/ -name .svn -type d | ${XARGS} -J % ${RM} -fr %

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/web_app/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
