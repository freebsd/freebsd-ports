PORTNAME=	sslscan
DISTVERSION=	2.0.16
CATEGORIES=	security
MASTER_SITES=	https://www.openssl.org/source/:openssl \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/:openssl
DISTFILES=	openssl-${OPENSSL_VERSION}.tar.gz:openssl

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	Fast SSL port scanner
WWW=		https://github.com/rbsec/sslscan/

LICENSE=	GPLv3

USES=		gmake perl5
USE_PERL5=	build
USE_GITHUB=	yes
GH_ACCOUNT=	rbsec
OPENSSL_VERSION=	3.1.0

ALL_TARGET=	static

post-patch:
	$(LN) -sf "${WRKDIR}/openssl-${OPENSSL_VERSION}" "${WRKSRC}/openssl"

.include <bsd.port.mk>
