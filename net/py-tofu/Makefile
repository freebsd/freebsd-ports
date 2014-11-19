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
USES=		python twisted tar:bzip2
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/Tofu-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-tofu
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
