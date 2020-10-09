# $FreeBSD$

PORTNAME=	intel-ipsec-mb
DISTVERSION=	0.54.3
DISTVERSIONSUFFIX=	-dev
CATEGORIES=	security

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Intel(R) Multi-Buffer Crypto for IPsec Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	nasm:devel/nasm

USES=		gmake compiler:c11 localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_TAGNAME=	76949db

USE_LDCONFIG=	yes
PLIST_FILES=	include/intel-ipsec-mb.h \
		lib/libIPSec_MB.so \
		lib/libIPSec_MB.so.0 \
		lib/libIPSec_MB.so.${DISTVERSION} \
		man/man7/libipsec-mb.7.gz

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/intel-ipsec-mb.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/lib/libIPSec_MB.so.${DISTVERSION}${DISTVERSIONSUFFIX} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.${DISTVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.0 ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so
	${INSTALL_MAN} ${WRKSRC}/lib/libipsec-mb.7 ${STAGEDIR}${PREFIX}/man/man7

do-test:
	cd ${WRKSRC}/test && ./ipsec_xvalid_test -v
	cd ${WRKSRC}/test && ./ipsec_MB_testapp --auto-detect

.include <bsd.port.mk>
