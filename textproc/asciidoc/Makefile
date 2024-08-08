PORTNAME=	asciidoc
PORTVERSION=	10.2.1
CATEGORIES=	textproc
MASTER_SITES=	PYPI

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages
WWW=		https://github.com/asciidoc-py/asciidoc-py

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl

USES=		gnome python shebangfix
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/a2x.1.gz \
		share/man/man1/asciidoc.1.gz

SHEBANG_FILES=	asciidoc/resources/filters/*.py \
		asciidoc/resources/filters/*/*.py


post-build:
	@cd ${WRKSRC}/ && ${PYTHON_CMD} -m asciidoc.a2x -f manpage doc/a2x.1.txt
	@cd ${WRKSRC}/ && ${PYTHON_CMD} -m asciidoc.a2x -f manpage doc/asciidoc.1.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${WRKSRC}/doc/asciidoc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
