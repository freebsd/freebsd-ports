# New ports collection makefile for:	mmtk
# Date created:		29 August 2002
# Whom:			Glenn Johnson <gjohnson@srrc.ars.usda.gov>
#
# $FreeBSD$
#

PORTNAME=	mmtk
PORTVERSION=	2.2
CATEGORIES=	science python
MASTER_SITES=	http://starship.python.net/crew/hinsen/MMTK/
DISTNAME=	MMTK-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Open Source program library for molecular simulation applications

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Scientific:${PORTSDIR}/math/py-scientific
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Scientific:${PORTSDIR}/math/py-scientific

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

MAJOR!=	${UNAME} -r | ${SED} -e 's/\..*//'

PLIST_SUB+=	MAJOR=${MAJOR}

post-patch:
	@${REINPLACE_CMD} "s#'Include'#'Include','${PREFIX}/include'#" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "s#malloc.h#stdlib.h#g" ${WRKSRC}/Include/MMTK/readdcd.h

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC} -chf - Doc | \
		${TAR} -xf - -C ${DOCSDIR}
	@${TAR} -C ${WRKSRC} -chf - Examples | \
		${TAR} -xf - -C ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
