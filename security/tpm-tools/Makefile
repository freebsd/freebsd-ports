# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	tpm-tools
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/trousers/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Provides a basic set of TPM tools

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	tspi:${PORTSDIR}/security/trousers
BUILD_DEPENDS=	pkcsconf:${PORTSDIR}/security/opencryptoki
RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:${PORTSDIR}/security/trousers \
		${LOCALBASE}/lib/pkcs11/libopencryptoki.so:${PORTSDIR}/security/opencryptoki

USES=		gettext gmake iconv
USE_LDCONFIG=	YES
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib -lintl -liconv
MAKE_JOBS_SAFE=	YES

MAN1=		tpm_sealdata.1 tpm_version.1				\
		tpmtoken_import.1 tpmtoken_init.1 tpmtoken_objects.1	\
		tpmtoken_protect.1 tpmtoken_setpasswd.1

MAN3=		tpmUnsealFile.3 tpmUnsealShred.3 tpmUnsealStrerror.3

MAN8=		tpm_changeownerauth.8 tpm_clear.8 tpm_createek.8	\
		tpm_getpubek.8 tpm_resetdalock.8 tpm_restrictpubek.8	\
		tpm_revokeek.8 tpm_selftest.8 tpm_setactive.8		\
		tpm_setclearable.8 tpm_setenable.8 tpm_setoperatorauth.8 \
		tpm_setownable.8 tpm_setpresence.8 tpm_takeownership.8

.include <bsd.port.mk>
