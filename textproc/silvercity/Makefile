# Created by: ijliao
# $FreeBSD$

PORTNAME=	silvercity
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Python%20SilverCity%20Bindings/${PORTVERSION}
DISTNAME=	SilverCity-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexing package for over 20 programming and markup languages

USES=		dos2unix python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	SilverCity

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/SilverCity/_SilverCity.so

.include <bsd.port.mk>
