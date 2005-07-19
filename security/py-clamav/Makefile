# New ports collection makefile for:	py-clamav
# Date created:				26 Dec 2004
# Whom:					Marcus Grando <marcus@corp.grupos.com.br>
#
# $FreeBSD$
#

PORTNAME=		clamav
PORTVERSION=		0.3.1
CATEGORIES=		security python
MASTER_SITES=		http://xael.org/norman/python/pyclamav/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		py${PORTNAME}-${PORTVERSION}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A python binding to libclamav written in C

LIB_DEPENDS=		clamav.1:${PORTSDIR}/security/clamav

DIST_SUBDIR=		python
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=		yes

PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

DOCSDIR?=		${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR?=		${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stat64|stat|g' ${WRKSRC}/pyclamav.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.py ${EXAMPLESDIR}

.include <bsd.port.mk>
