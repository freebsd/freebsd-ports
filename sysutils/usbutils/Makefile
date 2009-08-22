# New ports collection makefile for:	usbutils
# Date created:		14 Nov 2007
# Whom:			Henrik Brix Andersen <brix@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	usbutils
PORTVERSION=	0.73
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-usb/${PORTNAME}/${PORTVERSION}

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Utility for listing USB devices

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${DATADIR}

MAN8=		lsusb.8
PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
