# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkpgcounter
PORTVERSION=	3.50
PORTREVISION=	3
CATEGORIES=	print python
MASTER_SITES=	http://www.pykota.com/software/pkpgcounter/download/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Count pages and ink coverage percent

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:2.7
USE_PYTHON=	distutils
PORTDOCS=	README COPYING BUGS CREDITS NEWS
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e '/^directory.*man1/s|=.*|= "man/man1"|' \
		-e '/^docdir/s|".*"|"${DOCSDIR}"|' \
		${_SED_NODOCS} ${WRKSRC}/setup.py

.include <bsd.port.mk>
