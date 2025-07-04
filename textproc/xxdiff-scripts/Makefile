PORTNAME=	xxdiff
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-scripts

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Helper scripts for xxdiff
WWW=		http://furius.ca/xxdiff/doc/xxdiff-scripts.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xxdiff:textproc/xxdiff

USES=		python
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	xxdiff-scripts
MASTERDIR=	${.CURDIR}/../xxdiff

.include "${MASTERDIR}/Makefile.master"
