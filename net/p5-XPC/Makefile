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
MASTER_SITES=	http://www.focusresearch.com/gregor/sw/XPC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	XML Procedure Call (XPC)

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Daemon.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	XPC.3 XPC::Agent.3 XPC::Daemon.3

.include <bsd.port.mk>
