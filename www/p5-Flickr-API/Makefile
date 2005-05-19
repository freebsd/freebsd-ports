# ex:ts=8
# Ports collection makefile for:	Flickr::API
# Date created:			May 19, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Flickr-API
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Flickr
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	Perl interface to the Flickr API

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Parser/Lite/Tree.pm:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Flickr::API.3 Flickr::API::Request.3 Flickr::API::Response.3

.include <bsd.port.mk>
