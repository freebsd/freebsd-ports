# ex:ts=8
# Ports collection Makefile for:	roap
# Date created:			Apr 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	roap
PORTVERSION=	0.1.2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCS=	README README.ja USAGE USAGE.ja

do-build:
	@${SETUP_CMD} build

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roap ${PREFIX}/bin
	@${SETUP_CMD} install
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${CP} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
