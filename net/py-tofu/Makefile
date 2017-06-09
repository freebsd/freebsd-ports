# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	tofu
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Tofu-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Practical high-level network game engine

LICENSE=	GPLv2+

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USES=		python twisted tar:bzip2
USE_PYTHON=	autoplist distutils
EXAMPLESDIR=	${PREFIX}/share/examples/py-tofu
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
