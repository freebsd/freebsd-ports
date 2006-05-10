# New ports collection makefile for:	lsdvd
# Date created:		2004-03-30
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	lsdvd
PORTVERSION=	0.15
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	acidrip

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Print information about the contents and structure of a DVD

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
PLIST_FILES=	bin/lsdvd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
WITH_DVD_DEVICE?=/dev/acd0c
.else
WITH_DVD_DEVICE?=/dev/acd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${WITH_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
	@${ECHO_MSG} "===>"

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/dvd|${WITH_DVD_DEVICE}|' \
		${WRKSRC}/lsdvd.c

.include <bsd.port.post.mk>
