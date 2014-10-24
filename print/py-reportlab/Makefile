# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reportlab
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP \
		http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PFBFER}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Library to create PDF documents using the Python language

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

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
DOCS=		reportlab-userguide.pdf

OPTIONS_DEFINE=	CJK FREETYPE DOCS
OPTIONS_DEFAULT=	CJK FREETYPE
CJK_DESC=	Adobe CMaps

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/adobe-cmaps/ac15/cid2code.txt:${PORTSDIR}/print/adobe-cmaps
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTDIR%%|${DISTDIR}|' \
			  -e 's|%%PFBFER%%|${PFBFER}|' \
				${WRKSRC}/setup.py
.if ${PORT_OPTIONS:MDOCS}
.for f in genAll.py userguide/genuserguide.py
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|' \
			  -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' \
				${WRKSRC}/docs/${f}
.endfor
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${PYTHON_CMD} genAll.py
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
