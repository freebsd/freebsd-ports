# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.11
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/reportlab
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

REPORTLABDIR=	${PYTHON_SITELIBDIR}/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

post-patch:
	${MV} ${WRKSRC}/lib/setup.py ${WRKDIR}

do-build:
	@(cd ${WRKDIR}; \
		${PYTHON_CMD} setup.py build)

do-install:
	@${MKDIR} ${REPORTLABDIR}
.for dir in . lib extensions graphics pdfbase pdfgen platypus
	@${MKDIR} ${REPORTLABDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.py ${REPORTLABDIR}/${dir}
.endfor
	@(cd ${WRKDIR}; \
		${PYTHON_CMD} setup.py install)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/demos; tar cpf - * | (cd ${EXAMPLEDIR}; tar xpf -)

	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DOCDIR}
.endif

.include <bsd.port.mk>
