# New ports collection makefile for:	gist
# Date created:		2009-08-16
# Whom:			Ricky E. <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	3.1.0
PORTREVISION=	2
CATEGORIES=	www net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	A gist pastebin posting command

CONFLICTS=	p5-App-gist-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	defunkt
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	82ffb80

MAN1=		gist.1

USE_RUBY=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/gist

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gist ${PREFIX}/bin/gist
	${INSTALL_MAN} ${WRKSRC}/man/gist.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
