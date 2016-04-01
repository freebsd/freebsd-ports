# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	sasql
PORTVERSION=	3.2.0
PORTREVISION=	3
CATEGORIES=	mail www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edit SpamAssassin settings stored in an SQL DB

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB

USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/\(\$$imap_server_type == \'cyrus\'\)/\1 || \$$imap_server_type == \'courier\'/g" \
		-e 's/session_register/sqsession_register/g' \
		${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/sasql_hooks.php
	-@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/*.bak ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/.cvsignore

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
