# New ports collection makefile for:	pgen
# Date created:				30 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pgen
PORTVERSION=	0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.happygiraffe.net/dist/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool to generate a procmailrc file with m4 macros

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

NO_BUILD=	yes

MAN1=	pgen.1

post-patch:
	@${REINPLACE_CMD} -e 's!{INSTALL_PROGRAM}!{INSTALL_SCRIPT}!g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
