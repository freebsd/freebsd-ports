# $FreeBSD$

PORTNAME=	wikicloth
PORTVERSION=	0.8.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby parser for the MediaWiki markup language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-expression_parser>=0:${PORTSDIR}/math/rubygem-expression_parser \
		rubygem-htmlentities>=0:${PORTSDIR}/textproc/rubygem-htmlentities \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-twitter-text>=0:${PORTSDIR}/textproc/rubygem-twitter-text

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
