PORTNAME=	stackdriver-core
PORTVERSION=	1.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internal shared library for the Ruby Stackdriver integration libraries
WWW=		https://cloud.google.com/ruby/docs/reference/stackdriver-core/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/stackdriver-core \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-cloud-core>=1.2<2:net/rubygem-google-cloud-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
