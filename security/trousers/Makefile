# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	trousers
PORTVERSION=	0.3.10
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	The open-source TCG Software Stack

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		alias autoreconf gmake iconv libtool pkgconfig
USE_OPENSSL=	YES
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
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
USERS=		_tss
GROUPS=		_tss

OPTIONS_DEFINE=	EMULATOR DEBUG
EMULATOR_DESC=	Build for use with the tpm-emulator
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMULATOR}
PKGNAMESUFFIX+=	-no_tddl
LIB_DEPENDS+=	libtddl.so:emulators/tpm-emulator

EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-tcs-Makefile.am \
		${FILESDIR}/extra-patch-src-tcsd-Makefile.am \
		${FILESDIR}/extra-patch-src-tddl-Makefile.am
# The emulator has already a libttddl.so, so comment out trousers' libtddl in the pkg-plist
PLIST_SUB+=	TDDL="@comment "
.else
PKGNAMESUFFIX+=	-tddl
CONFLICTS+=	tpm-emulator-[0-9]*
PLIST_SUB+=	TDDL=""
.endif

post-install:
	${INSTALL_DATA} \
	    ${WRKSRC}/dist/tcsd.conf ${STAGEDIR}${PREFIX}/etc/tcsd.conf.dist
	${MKDIR} ${STAGEDIR}${PREFIX}/var/lib/tpm

.include <bsd.port.mk>
