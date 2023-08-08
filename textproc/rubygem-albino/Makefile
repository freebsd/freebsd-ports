PORTNAME=	albino
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper for pygmentize
WWW=		https://github.com/github/albino

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:devel/rubygem-posix-spawn \
		${PYTHON_PKGNAMEPREFIX}pygments>=0.8:textproc/py-pygments@${PY_FLAVOR}

USES=		gem python shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	vendor/multipygmentize

.include <bsd.port.mk>
