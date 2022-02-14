# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	gollum-lib
PORTVERSION=	5.1.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione>=4.1:graphics/rubygem-gemojione \
		rubygem-github-markup>=1.6:textproc/rubygem-github-markup \
		rubygem-gollum-rugged_adapter>=1.0<2.0:www/rubygem-gollum-rugged_adapter \
		rubygem-nokogiri>=1.8.0<2.0:textproc/rubygem-nokogiri \
		rubygem-rouge>=3.1<4:textproc/rubygem-rouge \
		rubygem-twitter-text1=1.14.7:textproc/rubygem-twitter-text1 \
		rubygem-loofah>=2.12.0:textproc/rubygem-loofah \
		rubygem-github-markup>=4.0.0<5.0:textproc/rubygem-github-markup \
		rubygem-gemojione>=3.3.0:graphics/rubygem-gemojione \
		rubygem-octicons>=12.0.0:misc/rubygem-octicons

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
