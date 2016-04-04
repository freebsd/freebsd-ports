# Created by: Neil Darlow <neil@darlow.co.uk>
# $FreeBSD$

PORTNAME=	avelsieve
PORTVERSION=	1.9.9
CATEGORIES=	mail www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SquirrelMail plugin for Server-Side Mail Filtering management

pre-install:
	${RM} -Rf ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/po
	${FIND} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME} -type f \
		\( -name '.cvsignore' -o -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
