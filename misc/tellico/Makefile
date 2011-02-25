# New ports collection makefile for:	bookcase
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	tellico
PORTVERSION=	1.3.5
PORTREVISION=	7
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Collection manager for KDE

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		poppler-qt:${PORTSDIR}/graphics/poppler-qt \
		yaz.4:${PORTSDIR}/net/yaz \
		exempi:${PORTSDIR}/textproc/exempi

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_PYTHON=	yes

CONFIGURE_ARGS+=	--disable-cdtext

OPTIONS=	CDDB "CDDB support" on \
		KCAL "KOrganizer support" on \
		AMAZON "Amazon search support" on \
		IMDB "IMDb search support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CDDB)
CONFIGURE_ARGS+=--disable-libkcddb
.else
LIB_DEPENDS+=	kcddb:${PORTSDIR}/multimedia/kdemultimedia3
.endif

.if defined(WITHOUT_KCAL)
CONFIGURE_ARGS+=--disable-libkcal
.else
LIB_DEPENDS+=	kcal.2:${PORTSDIR}/deskutils/kdepim3
.endif

.if defined(WITHOUT_AMAZON)
CONFIGURE_ARGS+=--disable-amazon
.endif

.if defined(WITHOUT_IMDB)
CONFIGURE_ARGS+=--disable-imdb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
