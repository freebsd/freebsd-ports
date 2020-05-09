# $FreeBSD$

PORTNAME=	testssl.sh
DISTVERSION=	3.0.2
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Test TLS/SSL encryption anywhere on any port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/openssl-unsafe/bin/openssl:security/openssl-unsafe \
		bash:shells/bash
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	drwetter
USE_PERL5=	test
SHEBANG_FILES=	testssl.sh utils/*
TEST_ENV=	TESTSSL_INSTALL_DIR=${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e '/elif test_openssl_suffix/d' \
		-e 's@OPENSSL=PREFIX@OPENSSL=${PREFIX}@' \
		-e 's@$${TESTSSL_INSTALL_DIR:-""}@$${TESTSSL_INSTALL_DIR:-"${DATADIR}"}@' \
		-e '/check_bsd_mount$$/d' \
		${WRKSRC}/testssl.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/testssl.sh \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/testssl.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "etc utils" ${STAGEDIR}${DATADIR}

do-test:
# Run the badssl.com test as a sanity check.  The full test suite
# opens too many network connections and might take too long to
# run.
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} prove -v t/51_badssl.com.t

.include <bsd.port.mk>
