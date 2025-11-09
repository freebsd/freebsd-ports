PORTNAME=	net-http
PORTVERSION=	0.6.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	HTTP client api for Ruby
WWW=		https://github.com/ruby/net-http

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-uri-gitlab>=0:net/rubygem-uri-gitlab

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.6\.

.include <bsd.port.mk>
