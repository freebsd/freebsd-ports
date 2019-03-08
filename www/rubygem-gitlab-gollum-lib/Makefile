# $FreeBSD$

PORTNAME=	gitlab-gollum-lib
PORTVERSION=	4.2.7.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione32>=3.2:graphics/rubygem-gemojione32 \
		rubygem-gitlab-markup>=1.6:textproc/rubygem-gitlab-markup \
		rubygem-gollum-grit_adapter10>=1.0:www/rubygem-gollum-grit_adapter10 \
		rubygem-nokogiri>=1.6.1:textproc/rubygem-nokogiri \
		rubygem-rouge>=3.1:textproc/rubygem-rouge \
		rubygem-sanitize>=4.6.4:textproc/rubygem-sanitize \
		rubygem-stringex>=2.6:devel/rubygem-stringex

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
