# New ports collection makefile for:	tpp
# Date created:				2004-08-30
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	tpp
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://synflood.at/tpp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text presentation program

RUN_DEPENDS=	${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses \
		figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

MAN1=	tpp.1

.include <bsd.port.mk>
