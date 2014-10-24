# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reportlab
PORTVERSION=	1.21.2
PORTREVISION=	3
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/ \
		${MASTER_SITE_LOCAL:S/$/:accel/} \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/:accel
MASTER_SITE_SUBDIR=	erwin/:accel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTFILES=	reportlab-${PORTVERSION}.tar.gz \
		rl_accel-3004.tgz:accel

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Library to create PDF documents using the Python language

CONFLICTS=	py*-reportlab[^1]-[^1].* \
		py*-reportlab-[^1].*

PORTSCOUT=	ignore:1	# Last version of 1.X branch

USES=		python
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/reportlab_${PORTVERSION:S/./_/g}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	RML_UserGuide.pdf RML_UserGuide_1_0.pdf diagradoc.pdf graphguide.pdf \
	graphics_reference.pdf reference.pdf userguide.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py
	@${REINPLACE_CMD} -e 's#with#with26#g' ${WRKSRC}/lib/PyFontify.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${CP} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
