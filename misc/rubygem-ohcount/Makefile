# New ports collection makefile for:	ohcount
# Date created:		2009-05-31
# Whom:			Edmondas Girkantas <eg@fbsd.lt>
#
# $FreeBSD$
#

PORTNAME=	ohcount
PORTVERSION=	2.0.1
CATEGORIES=	misc rubygems
MASTER_SITES=	http://labs.ohloh.net/download/

MAINTAINER=	eg@fbsd.lt
COMMENT=	Ohcount is the source code line counter that powers Ohloh

BUILD_DEPENDS=	rubygem-diff-lcs>=1.1.2:${PORTSDIR}/textproc/rubygem-diff-lcs \
		ragel:${PORTSDIR}/devel/ragel
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ohcount

.include <bsd.port.mk>
