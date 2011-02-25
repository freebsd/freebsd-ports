# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.21.2
PORTREVISION=	3
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/ \
		${MASTER_SITE_LOCAL:S/$/:accel/} \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/:accel
MASTER_SITE_SUBDIR=	erwin/:accel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	reportlab-${PORTVERSION}.tar.gz \
		rl_accel-3004.tgz:accel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Reportlab

WRKSRC=		${WRKDIR}/reportlab_${PORTVERSION:S/./_/g}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCS=	RML_UserGuide.pdf RML_UserGuide_1_0.pdf diagradoc.pdf graphguide.pdf \
	graphics_reference.pdf reference.pdf userguide.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py
	@${REINPLACE_CMD} -e 's#with#with26#g' ${WRKSRC}/lib/PyFontify.py

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${CP} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
