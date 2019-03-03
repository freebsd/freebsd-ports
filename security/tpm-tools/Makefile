# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	tpm-tools
PORTVERSION=	1.3.9.1
CATEGORIES=	security
MASTER_SITES=	SF/trousers/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Provides a basic set of TPM tools

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:security/trousers
BUILD_DEPENDS=	${LOCALBASE}/sbin/pkcsconf:security/opencryptoki
RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:security/trousers \
		${LOCALBASE}/lib/pkcs11/libopencryptoki.so:security/opencryptoki

USES=		autoreconf gettext gmake iconv libtool ssl
USE_LDCONFIG=	YES

NO_WRKSUBDIR=	YES
GNU_CONFIGURE=	YES
LIBS+=		-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} '/^libtpm_unseal_la_LIBADD =/s/$$/ -lcrypto/' \
	    ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
