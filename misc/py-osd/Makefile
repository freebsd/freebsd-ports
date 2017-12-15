# Created by: larse@isi.edu
# $FreeBSD$

PORTNAME=	osd
PORTVERSION=	0.2.14
PORTREVISION=	11
CATEGORIES=	misc python
MASTER_SITES=	http://ichi2.net/pyosd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyosd-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python wrapper for osd, for displaying text on your X display

LIB_DEPENDS=	libxosd.so:misc/xosd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	AUTHORS ChangeLog ChangeLog.old README README.daemon pyosd.html
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
