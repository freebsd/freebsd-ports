# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	gollum-lib
PORTVERSION=	4.2.10
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione>=3.2<4:graphics/rubygem-gemojione \
		rubygem-github-markup>=1.6:textproc/rubygem-github-markup \
		rubygem-gollum-grit_adapter10>=1.0<2:www/rubygem-gollum-grit_adapter10 \
		rubygem-nokogiri>=1.6.1<2.0:textproc/rubygem-nokogiri \
		rubygem-rouge2>=2.1<3:textproc/rubygem-rouge2 \
		rubygem-sanitize>=2.1:textproc/rubygem-sanitize \
		rubygem-stringex>=2.6,1<3,1:devel/rubygem-stringex \
		rubygem-twitter-text1=1.14.7:textproc/rubygem-twitter-text1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
