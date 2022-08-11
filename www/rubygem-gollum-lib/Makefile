PORTNAME=	gollum-lib
PORTVERSION=	5.1.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione>=4.1<5:graphics/rubygem-gemojione \
		rubygem-github-markup>=4.0<5:textproc/rubygem-github-markup \
		rubygem-gollum-rugged_adapter>=1.0<2:www/rubygem-gollum-rugged_adapter \
		rubygem-loofah>=2.3<3:textproc/rubygem-loofah \
		rubygem-nokogiri>=1.8<2:textproc/rubygem-nokogiri \
		rubygem-octicons>=12.0:misc/rubygem-octicons \
		rubygem-rouge>=3.1<4:textproc/rubygem-rouge \
		rubygem-twitter-text1>=1.14.7<1.14.8:textproc/rubygem-twitter-text1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
