# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
PORTVERSION=	0.7.4.a
PORTREVISION=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://www.xs4all.nl/%7Ejjvrieze/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.(.)$/\1/}

MAINTAINER=	will@FreeBSD.org
COMMENT=	KDE frontend to mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/kmplayer
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--with-x=${X11BASE} --disable-debug

post-patch:
# remove -pedantic where possible to fix build errors on -CURRENT
# remove optimizations
	@${REINPLACE_CMD} -e \
		's|-O2||; s|-pedantic ||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# do not try to roll our own mimetypes
	@${REINPLACE_CMD} -E -e \
		's|^(SUBDIRS.*)mimetypes|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
