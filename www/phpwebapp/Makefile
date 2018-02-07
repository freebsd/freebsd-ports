# Created by: ijliao
# $FreeBSD$

PORTNAME=	phpwebapp
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web application framework

EXPIRATION_DATE=	2018-03-07
DEPRECATED=	Unmaintained upstream, all www files wrongly belongs to www user.

NO_ARCH=	yes
NO_BUILD=	yes
USES=		php:web shebangfix

SHEBANG_FILES=	web_app/boxes/menu/edit/xsl/test/*.sh \
		web_app/boxes/webnotes/db/dump.sh \
		web_app/convert/convert.php \
		web_app/l10n/*.sh \
		web_app/l10n-module/app/*.sh

post-patch:
	@${FIND} ${WRKSRC}/web_app/ -name .svn -type d | ${XARGS} -J % ${RM} -r %

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/web_app/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
