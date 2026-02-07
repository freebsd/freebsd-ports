PORTNAME=	swd
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple Web Discovery Client Library
WWW=		https://github.com/nov/swd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=3:devel/rubygem-activesupport-gitlab \
		rubygem-attr_required>=0.0.5:devel/rubygem-attr_required \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0:www/rubygem-faraday-follow_redirects-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
