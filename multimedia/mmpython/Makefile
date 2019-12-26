# Created by: larse@isi.edu
# $FreeBSD$

PORTNAME=	mmpython
PORTVERSION=	0.4.10
PORTREVISION=	10
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieves metadata from mp3, ogg, avi, jpg, and other formats

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
RUN_DEPENDS=	lsdvd:multimedia/lsdvd

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/local/,${LOCALBASE}/,g' \
		-e 's|gcc -ldvdread|gcc -L${LOCALBASE}/lib -ldvdread|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mmpython/disc/*.so

.include <bsd.port.mk>
