# New ports collection makefile for:	gist
# Date created:		2009-08-16
# Whom:			Ricky E. <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	1.0
CATEGORIES=	www net
MASTER_SITES=	http://github.com/defunkt/gist/raw/master/
DISTNAME=	gist
EXTRACT_SUFX=	.rb
EXTRACT_ONLY=

MAINTAINER=	codeblock@eighthbit.net
COMMENT=	A gist pastebin posting command

CONFLICTS=	p5-WWW-GitHub-Gist-[0-9]*

USE_RUBY=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/gist

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/gist.rb ${PREFIX}/bin/gist

.include <bsd.port.mk>
