# Created by: larse@isi.edu
# $FreeBSD$

PORTNAME=	mmpython
PORTVERSION=	0.4.10
PORTREVISION=	7
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieves metadata from mp3, ogg, avi, jpg, and other formats

LICENSE=	GPLv2

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	lsdvd:${PORTSDIR}/multimedia/lsdvd

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/local/,${LOCALBASE}/,g' \
		-e 's|gcc -ldvdread|gcc -L${LOCALBASE}/lib -ldvdread|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
