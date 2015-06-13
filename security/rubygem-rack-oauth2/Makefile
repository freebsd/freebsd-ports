# $FreeBSD$

PORTNAME=	rack-oauth2
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OAuth 2.0 Server & Client Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=2.3:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-attr_required>=0.0.5:${PORTSDIR}/devel/rubygem-attr_required \
		rubygem-httpclient>=2.4:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-multi_json>=1.3.6:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack16>=1.1:${PORTSDIR}/www/rubygem-rack16

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
