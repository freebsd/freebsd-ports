PORTNAME=	tpm2-pkcs11
PORTVERSION=	1.9.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-pkcs11/releases/download/${PORTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	PKCS\#11 interface for TPM2 hardware
WWW=		https://tpm2-software.github.io/software/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml \
		libtss2-esys.so:security/tpm2-tss

USES=		libtool pkgconfig sqlite:3 ssl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check-TESTS

OPTIONS_DEFINE=	TEST

TEST_USES=		python
TEST_CONFIGURE_ENABLE=	ptool-checks unit
TEST_LIB_DEPENDS=	libcmocka.so:sysutils/cmocka
TEST_RUN_DEPENDS=	dbus-run-session:devel/dbus

.include <bsd.port.mk>
