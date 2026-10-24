PORTNAME=	mkcacerts
DISTVERSION=	0.2.0
CATEGORIES=	security java

MAINTAINER=	michaelo@FreeBSD.org
COMMENT=	Generate a Java PKCS#12 truststore from certctl(8)'s truststore
WWW=		https://github.com/michael-o/freebsd-mkcacerts

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl
USE_GITHUB=	yes
GH_ACCOUNT=	michael-o
GH_PROJECT=	freebsd-mkcacerts

NO_TEST=	yes

PLIST_FILES=	sbin/mkcacerts \
		share/man/man8/mkcacerts.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkcacerts ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mkcacerts.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
