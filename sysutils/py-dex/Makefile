PORTNAME=	dex
PORTREVISION=	1
DISTVERSION=	0.10.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	99492884c0ec39b03785cb8efe2c4a23af3099fc.patch:-p1 # https://github.com/jceb/dex/pull/78

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	DesktopEntry Execution

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jceb

SHEBANG_FILES=	dex

NO_ARCH=	yes

PLIST_FILES=	bin/dex \
		share/man/man1/dex.1.gz

do-build:
	@cd ${WRKSRC} && sphinx-build -b man -D version=$(TAG) -E man . man/dex.rst

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dex.1 ${STAGEDIR}${PREFIX}/share/man/man1/dex.1

.include <bsd.port.mk>
