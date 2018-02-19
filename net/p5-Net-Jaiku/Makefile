# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Jaiku
PORTVERSION=	0.0501
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to jaiku.com's API #'

DEPRECATED=	Upstream disappeared and jaiku.com returns 404
EXPIRATION_DATE=2018-03-31

RUN_DEPENDS=	p5-libwww>=5.805:www/p5-libwww \
		p5-JSON-Any>0:converters/p5-JSON-Any \
		p5-Params-Validate>0:devel/p5-Params-Validate
BUILD_DEPENDS=	p5-libwww>=5.805:www/p5-libwww \
		p5-JSON-Any>0:converters/p5-JSON-Any \
		p5-Params-Validate>0:devel/p5-Params-Validate

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
