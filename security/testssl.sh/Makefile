# $FreeBSD$

PORTNAME=	testssl.sh
DISTVERSION=	3.0rc4
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Test TLS/SSL encryption anywhere on any port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/openssl-unsafe/bin/openssl:security/openssl-unsafe

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	drwetter

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	testssl.sh utils/*

post-patch:
	@${REINPLACE_CMD} -e '/elif test_openssl_suffix/d' \
		-e 's@OPENSSL=PREFIX@OPENSSL=${PREFIX}@' \
		-e 's@$${TESTSSL_INSTALL_DIR:-""}@$${TESTSSL_INSTALL_DIR:-"${DATADIR}"}@' \
		-e '/check_bsd_mount$$/d' \
		${WRKSRC}/testssl.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/testssl.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/testssl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/etc ${STAGEDIR}${DATADIR}/utils
	@cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/etc
	@cd ${WRKSRC}/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils

.include <bsd.port.mk>
