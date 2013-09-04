# Created by: Neil Darlow <neil@darlow.co.uk>
# $FreeBSD$

PORTNAME=	avelsieve
PORTVERSION=	1.9.7
PORTREVISION=	2
DIST_SUBDIR=	squirrelmail

MAINTAINER=	neil@darlow.co.uk
COMMENT=	SquirrelMail plugin for Server-Side Mail Filtering management

USES=		perl5
USE_PERL5=	run

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"

pre-install:
	${RM} -Rf ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/po
	${FIND} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME} -type f \
		\( -name '.cvsignore' -o -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;

.include <bsd.port.mk>
