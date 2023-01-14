PORTNAME=	mimemagic
PORTVERSION=	0.4.3
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MIME detection by extension or content in pure ruby
WWW=		https://github.com/mimemagicrb/mimemagic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1<2:textproc/rubygem-nokogiri \
		rubygem-rake>=0:devel/rubygem-rake \
		shared-mime-info>=0:misc/shared-mime-info

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
