PORTNAME=	sasql
PORTVERSION=	3.2.0
PORTREVISION=	3
CATEGORIES=	mail www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edit SpamAssassin settings stored in an SQL DB
WWW=		https://www.squirrelmail.org

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB@${PHP_FLAVOR}

IGNORE_WITH_PHP=	81 82 83
USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/\($$imap_server_type == 'cyrus'\)/\1 || \$$imap_server_type == 'courier'/g" \
		-e 's/session_register/sqsession_register/g' \
		${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/sasql_hooks.php
	-@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/*.bak ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/.cvsignore

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
