# New ports collection makefile for:	gplink
# Date created:				Sun Dec  5 23:17:44 CET 2004
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	gplink
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://gp2x.org/gp32/gplink/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GP32 USB linker tool

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/gplink

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

post-patch:
.if ${OSVERSION} >= 800069
	@${REINPLACE_CMD} -E -e 's,`libusb-config --cflags`,,g' \
		-e 's,`libusb-config --libs`,-lusb,g' \
		${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplink ${PREFIX}/bin

.include <bsd.port.post.mk>
