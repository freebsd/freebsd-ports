# New ports collection makefile for:	raggle
# Date created:				04 September 2003
# Whom:					gslin@ccca.nctu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	raggle
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A console RSS aggregator written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/rexml/rexml.rb:${PORTSDIR}/textproc/ruby-rexml	\
		${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses	\
		${RUBY_SITELIBDIR}/yaml.rb:${PORTSDIR}/devel/ruby-yaml

USE_RUBY=	yes

NO_BUILD=	yes

MAN1=		raggle.1

.include <bsd.port.mk>
