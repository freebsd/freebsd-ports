# New ports collection makefile for:	opencryptoki
# Date created:				2010-07-16
# Whom:					Ralf Meister
#
# $FreeBSD$
#

PORTNAME=	opencryptoki
PORTVERSION=	2.3.2
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open PKCS\#11 implementation library

LIB_DEPENDS=	tspi.2:${PORTSDIR}/security/trousers

USE_BZIP2=	YES
USE_GMAKE=	YES
USE_LDCONFIG=	YES
USE_AUTOTOOLS=	autoconf libtool automake
HAS_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES

USE_RC_SUBR=	pkcsslotd
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

MAN1=		pkcs11_startup.1 pkcsconf.1
MAN5=		pk_config_data.5
MAN7=		opencryptoki.7
MAN8=		pkcsslotd.8

USERS=		_pkcs11
GROUPS=		_pkcs11

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

CONFIGURE_ARGS=	--enable-swtok --enable-tpmtok \
		--disable-crtok --disable-aeptok \
		--disable-ccatok --disable-bcomtok \
		--disable-pkcscca_migrate \
		--libdir=${PREFIX}/lib \
		--sbindir=${PREFIX}/sbin \
		--localstatedir=${PREFIX}/var \
		--with-pkcs11user=${USERS} \
		--with-pkcs11group=${GROUPS}
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include

run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

post-install:
	@cd ${PREFIX}/lib && ${LN} -s opencryptoki/libopencryptoki* .
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
