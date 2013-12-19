# Created by: Neil Darlow <neil@darlow.co.uk>
# $FreeBSD$

PORTNAME=	avelsieve
PORTVERSION=	1.9.7
PORTREVISION=	3
CATEGORIES=		mail www

MAINTAINER=	neil@darlow.co.uk
COMMENT=	SquirrelMail plugin for Server-Side Mail Filtering management

NO_STAGE=	yes

pre-install:
	${RM} -Rf ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/po
	${FIND} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME} -type f \
		\( -name '.cvsignore' -o -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
