# $FreeBSD$

PORTNAME=	rox-mime-editor
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/rox/MIME-Editor/${PORTVERSION}
DISTNAME=	mime-editor-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIME type editor for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:devel/py-roxlib

USES=		python tar:bzip2

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
				${WRKSRC}/MIME-Editor/findrox.py
	@${FIND} ${WRKSRC} -name *.bak -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps
	@${CP} -r ${WRKSRC}/MIME-Editor ${STAGEDIR}${PREFIX}/apps/

.include <bsd.port.mk>
