# $FreeBSD$

PORTNAME=	wikicloth
PORTVERSION=	0.8.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	081

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby parser for the MediaWiki markup language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-expression_parser>=0:math/rubygem-expression_parser \
		rubygem-htmlentities>=0:textproc/rubygem-htmlentities \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-twitter-text>=0:textproc/rubygem-twitter-text

PORTSCOUT=	limit:^0\.8\.1

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
