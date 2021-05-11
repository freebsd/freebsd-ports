PORTNAME=	mimemagic
PORTVERSION=	0.4.3
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MIME detection by extension or content in pure ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	shared-mime-info>0:misc/shared-mime-info \
		rubygem-nokogiri>=1<2:textproc/rubygem-nokogiri \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
