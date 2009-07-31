# Ports collection Makefile for:	pkpgcounter
# Date created:				Jan 1 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkpgcounter
PORTVERSION=	3.50
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	http://www.pykota.com/software/pkpgcounter/download/tarballs/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Count pages and ink coverage precent

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		${PORTNAME}.1

PORTDOCS=	README COPYING BUGS CREDITS NEWS
.ifdef NOPORTDOCS
_SED_NODOCS=	-e '/^data_files.append.*docfiles/s|.*||'
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^directory.*man1/s|=.*|= "man/man1"|' \
		-e '/^docdir/s|".*"|"${DOCSDIR}"|' \
		${_SED_NODOCS} ${WRKSRC}/setup.py

.include <bsd.port.mk>
