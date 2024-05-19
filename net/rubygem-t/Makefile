PORTNAME=	t
PORTVERSION=	4.1.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter
WWW=		https://sferik.github.io/t-ruby/ \
		https://github.com/sferik/t-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-geokit>=1.14<2:graphics/rubygem-geokit \
		rubygem-htmlentities>=4.3<5:textproc/rubygem-htmlentities \
		rubygem-launchy>=3.0<4:devel/rubygem-launchy \
		rubygem-oauth>=1.1<2:net/rubygem-oauth \
		rubygem-retryable>=3.0<4:devel/rubygem-retryable \
		rubygem-thor>=1.3<2:devel/rubygem-thor \
		rubygem-twitter>=8.1<9:net/rubygem-twitter

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/t

.include <bsd.port.mk>
