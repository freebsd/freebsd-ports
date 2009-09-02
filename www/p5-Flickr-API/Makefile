# ex:ts=8
# Ports collection makefile for:	Flickr::API
# Date created:			May 19, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Flickr-API
PORTVERSION=	1.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to the Flickr API

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Parser/Lite/Tree.pm:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree

PERL_CONFIGURE=	yes

MAN3=		Flickr::API.3 Flickr::API::Request.3 Flickr::API::Response.3

.include <bsd.port.mk>
