# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	trousers
PORTVERSION=	0.3.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open-source TCG Software Stack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tpm-emulator>=0.7.4_1:emulators/tpm-emulator
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix alias autoreconf gmake iconv libtool pkgconfig ssl
DOS2UNIX_GLOB=	*.h *.c
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	YES
USE_RC_SUBR=	tcsd
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-gui=none --enable-static \
		--localstatedir=${PREFIX}/var \
		--with-tssuser=${USERS} \
		--with-tssgroup=${GROUPS} \
		--with-openssl=${OPENSSLBASE} \
		RANLIB=:
MAKE_ENV=	ICONV_LIB=${ICONV_LIB} \
		ICONV_PREFIX=${ICONV_PREFIX}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"
USERS=		_tss
GROUPS=		_tss

OPTIONS_DEFINE=	DEBUG
DEBUG_CONFIGURE_ENABLE=	debug

post-install:
	${INSTALL_DATA} \
	    ${WRKSRC}/dist/tcsd.conf ${STAGEDIR}${PREFIX}/etc/tcsd.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/lib/tpm

.include <bsd.port.mk>
