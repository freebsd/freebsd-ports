PORTNAME=	testssl.sh
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
CATEGORIES=	security

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Analyze and report TLS/SSL configuration/misconfiguration
WWW=		https://github.com/testssl/testssl.sh

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	openssl-unsafe>=1.0.1:security/openssl-unsafe \
		bash:shells/bash
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

USES=		perl5 shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	testssl

SHEBANG_FILES=	testssl.sh utils/*
SUB_LIST+=	OPENSSLBASE="${OPENSSLBASE}"

USE_PERL5=	test
TEST_ENV=	TESTSSL_INSTALL_DIR=${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/testssl.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/testssl.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/testssl.1 ${STAGEDIR}${PREFIX}/share/man/man1
	cd ${WRKSRC} && ${COPYTREE_SHARE} "etc utils" ${STAGEDIR}${DATADIR}

do-test:
# Run the badssl.com test as a sanity check.  The full test suite
# opens too many network connections and might take too long to
# run.
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} prove -v t/51_badssl.com.t

.include <bsd.port.mk>
