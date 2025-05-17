PORTNAME=	rails-dom-testing
PORTVERSION=	2.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Analyse and compare DOMs using Nokogiri
WWW=		https://github.com/rails/rails-dom-testing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=5.0.0:devel/rubygem-activesupport-gitlab \
		rubygem-minitest>=0:devel/rubygem-minitest \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
