# New ports collection makefile for:	lsdvd
# Date created:		2004-03-30
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	lsdvd
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	acidrip

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Print information about the contents and structure of a DVD

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

USE_REINPLACE=	yes
PLIST_FILES=	bin/lsdvd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/lsdvd.c

do-build:
	cd ${WRKSRC} && \
	${CC} -DPACKAGE=\"${PORTNAME}\" -DVERSION=\"${PORTVERSION}\" \
	-DHAVE_LIBDVDREAD=1 -I. -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-ldvdread lsdvd.c -o lsdvd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsdvd ${PREFIX}/bin

.include <bsd.port.post.mk>
