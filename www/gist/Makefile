# New ports collection makefile for:	gist
# Date created:		2009-08-16
# Whom:			Ricky E. <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	https://github.com/${GITAUTHOR}/${PORTNAME}/tarball/v${PORTVERSION}/
DISTNAME=	${GITAUTHOR}-${PORTNAME}-v${PORTVERSION}-0-g${GITCOMMIT}

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	A gist pastebin posting command

CONFLICTS=	p5-App-gist-[0-9]*

GITCOMMIT=	82ffb80
GITAUTHOR=	defunkt

USE_RUBY=	YES
NO_BUILD=	YES
FETCH_ARGS=	-r
WRKSRC=	${WRKDIR}/${GITAUTHOR}-${PORTNAME}-${GITCOMMIT}
PLIST_FILES=	bin/gist

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gist ${PREFIX}/bin/gist

.include <bsd.port.mk>
