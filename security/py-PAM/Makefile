PORTNAME=	PAM
DISTVERSION=	0.4.2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/p/python-pam
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-pam_${DISTVERSION}.orig

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Python interface to the PAM library
WWW=		https://packages.debian.org/sid/python3-pam

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_PYTHON=	allflavors autoplist concurrent distutils

SHEBANG_FILES=	examples/pamtest.py

WRKSRC=		${WRKDIR}/python-pam-${DISTVERSION}

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_PLIST_FILES=	${EXAMPLESDIR}/pamtest.py

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/pamtest.py ${STAGEDIR}${EXAMPLESDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/PAM${PYTHON_SOABI}.so

.include <bsd.port.mk>
