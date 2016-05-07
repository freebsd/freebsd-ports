# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reportlab
PORTVERSION=	3.2.0
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP \
		http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PFBFER}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS=	py*-reportlab[^3]-[^3].* \
		py*-reportlab-[^3].*

PORTSCOUT=	limit:^3\.0\.

PFBFER_VERSION=	20070710
PFBFER=	pfbfer-${PFBFER_VERSION}.zip

MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	reportlab-userguide.pdf

OPTIONS_DEFINE=	CJK FREETYPE DOCS
OPTIONS_DEFAULT=	CJK FREETYPE
CJK_DESC=	Adobe CMaps
CJK_RUN_DEPENDS=	${LOCALBASE}/share/fonts/adobe-cmaps/ac15/cid2code.txt:print/adobe-cmaps
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTDIR%%|${DISTDIR}|' \
			  -e 's|%%PFBFER%%|${PFBFER}|' \
				${WRKSRC}/setup.py

post-patch-DOCS-on:
.for f in genAll.py userguide/genuserguide.py
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|' \
			  -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' \
				${WRKSRC}/docs/${f}
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/reportlab/*/*.so

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && ${PYTHON_CMD} genAll.py
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
