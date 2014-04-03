# Created by: Nate Lawson <njl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpp
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	print
MASTER_SITES=	SF/cups/${PORTNAME}/${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	X11-based printer manager for CUPS

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client \
		libfltk.so.1:${PORTSDIR}/x11-toolkits/fltk
BUILD_DEPENDS=	${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-D_IPP_PRIVATE_STRUCTURES

PLIST_FILES=	bin/xpp share/doc/xpp/README
PLIST_DIRS=	share/doc/xpp

post-configure:
	@${REINPLACE_CMD} -e 's|$$(all_includes)|-I ${PREFIX}/include|' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|printFiles::get|get|' ${WRKSRC}/xpp.h

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xpp
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/xpp

.include <bsd.port.mk>
