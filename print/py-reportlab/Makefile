# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.02
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ReportLab_${PORTVERSION:S/./_/}.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/reportlab
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

REPORTLABDIR=	${PYTHON_SITELIBDIR}/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

post-extract:
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}/lib

do-configure:
	@(cd ${WRKSRC}/lib; \
		${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-build:
	@(cd ${WRKSRC}/lib; \
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET})

do-install:
	@${MKDIR} ${REPORTLABDIR}
.for dir in . lib pdfbase pdfgen platypus
	@${MKDIR} ${REPORTLABDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.py ${REPORTLABDIR}/${dir}
	-${INSTALL_DATA} ${WRKSRC}/${dir}/*.so ${REPORTLABDIR}/${dir}
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}

	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/demos; tar cpf - * | (cd ${EXAMPLEDIR}; tar xpf -)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}
.endif

.include <bsd.port.mk>
