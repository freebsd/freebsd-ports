PORTNAME=	rex-sslscan
PORTVERSION=	0.1.10
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) library for scanning SSL/TLS capabilities
WWW=		https://github.com/rapid7/rex-sslscan

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-socket>=0:security/rubygem-rex-socket \
		rubygem-rex-text>=0:security/rubygem-rex-text

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
