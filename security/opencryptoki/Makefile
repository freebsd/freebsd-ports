# Created by: Ralf Meister
# $FreeBSD$

PORTNAME=	opencryptoki
PORTVERSION=	2.3.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open PKCS\#11 implementation library

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:${PORTSDIR}/security/trousers

USES=		gmake
USE_BZIP2=	YES
USE_LDCONFIG=	YES
USE_AUTOTOOLS=	autoconf libtool automake
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-swtok --enable-tpmtok \
		--disable-crtok --disable-aeptok \
		--disable-ccatok --disable-bcomtok \
		--disable-pkcscca_migrate \
		--libdir=${PREFIX}/lib \
		--sbindir=${PREFIX}/sbin \
		--localstatedir=${PREFIX}/var \
		--with-pkcs11user=${USERS} \
		--with-pkcs11group=${GROUPS}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_RC_SUBR=	pkcsslotd
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
USERS=		_pkcs11
GROUPS=		_pkcs11

MAN1=		pkcs11_startup.1 pkcsconf.1
MAN5=		pk_config_data.5
MAN7=		opencryptoki.7
MAN8=		pkcsslotd.8

run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

post-install:
	@cd ${PREFIX}/lib && ${LN} -s opencryptoki/libopencryptoki* .
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
