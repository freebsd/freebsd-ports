# New ports collection makefile for:	gist
# Date created:		2009-08-16
# Whom:			Ricky E. <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	2.0.3
CATEGORIES=	www net
MASTER_SITES=	https://github.com/defunkt/${PORTNAME}/raw/v${PORTVERSION}/
DISTNAME=	gist
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gist pastebin posting command

CONFLICTS=	p5-App-gist-[0-9]*

USE_RUBY=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/gist

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/gist ${PREFIX}/bin/gist

.include <bsd.port.mk>
