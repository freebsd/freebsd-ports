# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	tofu
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Tofu-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Practical high-level network game engine

DIST_SUBDIR=	python
USE_BZIP2=	yes
USE_PYTHON=	yes
USES=		twisted
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Tofu
WRKSRC=		${WRKDIR}/Tofu-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-tofu

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
