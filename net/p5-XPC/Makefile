# ex:ts=8
# New ports collection makefile for:	p5-XPC
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XPC
PORTVERSION=	0.2
CATEGORIES=	net perl5
MASTER_SITES=	http://www.gregorpurdy.com/gregor/sw/XPC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Procedure Call (XPC)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/HTTP/Daemon.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XPC.3 XPC::Agent.3 XPC::Daemon.3

.include <bsd.port.mk>
