# $FreeBSD$

PORTNAME=	testssl.sh
PORTVERSION=	2.8
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Test TLS/SSL encryption anywhere on any port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		perl5 shebangfix ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	drwetter
GH_TUPLE=	drwetter:openssl-pm-snapshot:a9396aaef81d5c1ed714fc625b593522d25914b1:openssl
USE_PERL5=	build

SHEBANG_FILES=	testssl.sh utils/*

# We deliberately want to build an OpenSSL binary with the most
# insecure and obsolete ciphers available for testing purposes!  See
# ${WRKSRC_testssl}/bin/Readme.md and utils/make-openssl.sh for more
# details.
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--openssldir=${OPENSSLDIR} \
		enable-zlib \
		enable-ssl2 \
		enable-ssl3 \
		enable-ssl-trace \
		enable-rc5 \
		enable-rc2 \
		enable-gost \
		enable-cms \
		enable-md2 \
		enable-mdc2 \
		enable-ec \
		enable-ec2m \
		enable-ecdh \
		enable-ecdsa \
		enable-seed \
		enable-camellia \
		enable-idea \
		enable-rfc3779 \
		enable-ec_nistp_64_gcc_128 \
		experimental-jpake \
		-DOPENSSL_USE_IPV6
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_SCRIPT=	config

BUILD_WRKSRC=		${WRKSRC_openssl}
CONFIGURE_WRKSRC=	${WRKSRC_openssl}

# The build randomly fails sometimes when building in parallel for
# unknown reasons.
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/elif test_openssl_suffix/d' \
		-e 's@:    \# 5. we tried.*$$@else OPENSSL="${PREFIX}/libexec/openssl.testssl.sh"@' \
		-e 's@$${TESTSSL_INSTALL_DIR:-""}@$${TESTSSL_INSTALL_DIR:-"${DATADIR}"}@' \
		-e '/^check_bsd_mount$$/d' \
		${WRKSRC}/testssl.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC_openssl}/apps/openssl ${STAGEDIR}${PREFIX}/libexec/openssl.testssl.sh
	${INSTALL_SCRIPT} ${WRKSRC}/testssl.sh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/etc ${STAGEDIR}${DATADIR}/utils
	@cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/etc
	@cd ${WRKSRC}/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils

.include <bsd.port.mk>
