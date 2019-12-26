# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archivemail
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive and compress old email

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:2.7 shebangfix

USE_PYTHON=	distutils concurrent autoplist

SHEBANG_FILES=	test_archivemail

DOCS=		CHANGELOG FAQ NEWS README TODO
EXAMPLES=	test_archivemail examples/archivemail_all

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} test_archivemail

.include <bsd.port.mk>
