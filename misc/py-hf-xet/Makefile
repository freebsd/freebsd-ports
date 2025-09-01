PORTNAME=	hf-xet
DISTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast transfer of large files with the Hugging Face Hub
WWW=		https://github.com/huggingface/xet-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/hf_xet/LICENSE

BROKEN_i386=	fails to build: cannot find function `_mm256_insert_epi64` in this scope

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.7<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python ssl

USE_PYTHON=	autoplist pep517 pytest

CARGO_CARGOTOML=${WRKSRC}/hf_xet/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/hf_xet/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_ENV=	OPENSSL_NO_VENDOR=1

MAKE_ENV=	${CARGO_ENV}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/hf_xet/*.so

.include <bsd.port.mk>
