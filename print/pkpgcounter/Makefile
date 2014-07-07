# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkpgcounter
PORTVERSION=	3.50
PORTREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	http://www.pykota.com/software/pkpgcounter/download/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Count pages and ink coverage percent

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PORTDOCS=	README COPYING BUGS CREDITS NEWS
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e '/^directory.*man1/s|=.*|= "man/man1"|' \
		-e '/^docdir/s|".*"|"${DOCSDIR}"|' \
		${_SED_NODOCS} ${WRKSRC}/setup.py

.include <bsd.port.mk>
