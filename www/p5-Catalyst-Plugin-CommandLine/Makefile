# New ports collection makefile for:	p5-Catalyst-Plugin-CommandLine
# Date created:				Wed 22 Apr 2009
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-CommandLine
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Catalyst plugin to make controllers or models available for scripts

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/URI/http.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTTP/Headers.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	The module is not needed any more. With new Catalyst (at least 5.7014) it works out of the box.
EXPIRATION_DATE=	2010-11-10

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::CommandLine.3

.include <bsd.port.mk>
