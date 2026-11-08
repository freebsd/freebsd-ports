PORTNAME=	tweetstream
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple wrapper for consuming the Twitter Streaming API
WWW=		https://github.com/tweetstream/tweetstream

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-daemons>=1.1<2:devel/rubygem-daemons \
		rubygem-em-http-request>=1.1.1:www/rubygem-em-http-request \
		rubygem-em-twitter>=0.3<1:www/rubygem-em-twitter \
		rubygem-multi_json>=1.3<2:devel/rubygem-multi_json \
		rubygem-twitter>=5.5:net/rubygem-twitter

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	tweetstream_project

.include <bsd.port.mk>
