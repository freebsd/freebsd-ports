# Created by: larse@isi.edu
# $FreeBSD$

PORTNAME=	osd
PORTVERSION=	0.2.14
PORTREVISION=	8
CATEGORIES=	misc python
MASTER_SITES=	http://ichi2.net/pyosd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyosd-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A python wrapper for osd, for displaying text on your X display

LIB_DEPENDS=	libxosd.so:${PORTSDIR}/misc/xosd
RUN_DEPENDS=	${LOCALBASE}/bin/twistd:${PORTSDIR}/devel/py-twisted

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	AUTHORS ChangeLog ChangeLog.old README README.daemon pyosd.html
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
