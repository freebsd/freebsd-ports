PORTNAME=	ezcrypto
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Wrapper for the poorly documented OpenSSL ruby library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"test/store".freeze, ||' ${WRKSRC}/${GEMSPEC}

.include <bsd.port.mk>
