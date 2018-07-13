# Created by: sanpei@FreeBSD.org
# $FreeBSD$

PORTNAME=	amfm
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	https://github.com/ikegam/amfm/raw/9679aa06eead7ed3571480e892f426828e17e361/ \
		LOCAL/sanpei
DISTNAME=	amfm
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	THANKO USB AM/FM Radio controller

LICENSE=	NONE

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

LIB_DEPENDS=	libhid.so:devel/libhid

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amfm ${STAGEDIR}${PREFIX}/bin/amfm

.include <bsd.port.mk>
