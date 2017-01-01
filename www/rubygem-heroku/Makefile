# $FreeBSD$

PORTNAME=	heroku
PORTVERSION=	3.43.16
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Heroku Client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-heroku-api>=0.4.2:www/rubygem-heroku-api \
		rubygem-launchy>=2.4.3:devel/rubygem-launchy \
		rubygem-multi_json>=1.11.2:devel/rubygem-multi_json \
		rubygem-net-ssh>=2.9.2:security/rubygem-net-ssh \
		rubygem-net-ssh-gateway>=1.2.0:security/rubygem-net-ssh-gateway \
		rubygem-netrc>=0.10.3:net/rubygem-netrc \
		rubygem-rest-client>=1.6.8:www/rubygem-rest-client \
		rubygem-rubyzip>=1.1.7:archivers/rubygem-rubyzip

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/heroku

.include <bsd.port.mk>
