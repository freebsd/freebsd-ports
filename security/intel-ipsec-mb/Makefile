PORTNAME=	intel-ipsec-mb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
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

USE_LDCONFIG=	yes

PLIST_FILES=	include/intel-ipsec-mb.h \
		lib/libIPSec_MB.so \
		lib/libIPSec_MB.so.1 \
		lib/libIPSec_MB.so.${DISTVERSION}.0 \
		man/man7/libipsec-mb.7.gz

# While parallel compiling works it can easily eat up 8+ Gb of RAM which will
# result in unnecessary OOM errors
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	AESNIEMU
OPTIONS_DEFAULT=AESNIEMU

AESNIEMU_DESC=	Enable AESI-NI Emulation

AESNIEMU_MAKE_ARGS=	AESNI_EMU=y

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/intel-ipsec-mb.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/lib/libIPSec_MB.so.${DISTVERSION}.0 ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.${DISTVERSION}.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.${DISTVERSION}.0 ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so.${DISTVERSION}.0 ${STAGEDIR}${PREFIX}/lib/libIPSec_MB.so
	${INSTALL_MAN} ${WRKSRC}/lib/libipsec-mb.7 ${STAGEDIR}${PREFIX}/man/man7

do-test:
	${RLN} ${WRKSRC}/lib/libIPSec_MB.so.${DISTVERSION}.0 ${WRKSRC}/test/libIPSec_MB.so.1
	cd ${WRKSRC}/test && ./ipsec_xvalid_test -v
	cd ${WRKSRC}/test && ./ipsec_MB_testapp --auto-detect

.include <bsd.port.mk>
