PORTNAME=	swtpm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Libtpms-based TPM emulator
WWW=		https://github.com/stefanberger/swtpm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	base64>=0:converters/base64 \
		bash>=0:shells/bash \
		expect>=0:lang/expect \
		gawk>=0:lang/gawk \
		socat>=0:net/socat
LIB_DEPENDS=	libfuse.so:filesystems/fusefs-libs \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libjson-glib-1.0.so:devel/json-glib \
		libtasn1.so:security/libtasn1 \
		libtpms.so:sysutils/libtpms

USES=		autoreconf gettext-runtime gmake gnome libtool pathfix \
		pkgconfig python:env,test shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	stefanberger
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	tests/_* tests/test_clientfds.py tests/test_setdatafd.py

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tss-group=${GROUPS} \
			--with-tss-user=${USERS}

INSTALL_TARGET=	install-strip
TEST_ENV=	LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib/swtpm:${LD_LIBRARY_PATH} \
		PATH=${PATH}:${STAGEDIR}${PREFIX}/bin
TEST_TARGET=	./installed-runner.sh
TEST_WRKSRC=	${STAGEDIR}${PREFIX}/libexec/installed-tests/swtpm

USERS=		_tss
GROUPS=		${USERS}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${TEST_TARGET}

.include <bsd.port.mk>
