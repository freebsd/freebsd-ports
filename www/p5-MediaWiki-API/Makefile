# New ports collection makefile for:	p5-MediaWiki-API
# Date created:		23.09.2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MediaWiki-API
PORTVERSION=	0.27
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OOP MediaWiki engine client

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/JSON/XS.pm:${PORTSDIR}/converters/p5-JSON-XS \
		${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode

PERL_CONFIGURE=	yes

MAN3=		MediaWiki::API.3

.include <bsd.port.mk>
