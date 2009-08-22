# New ports collection makefile for:	xpp
# Date created:         23 Mar 2007
# Whom:                 Nate Lawson <njl@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xpp
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/cups/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based printer manager for CUPS

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-client \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk
BUILD_DEPENDS=	cupsd:${PORTSDIR}/print/cups-base

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xpp share/doc/xpp/README
PLIST_DIRS=	share/doc/xpp

post-configure:
	@${REINPLACE_CMD} -e 's|$$(all_includes)|-I ${PREFIX}/include|' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|printFiles::get|get|' ${WRKSRC}/xpp.h

post-install:	 
	${MKDIR} ${PREFIX}/share/doc/xpp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xpp

.include <bsd.port.mk>
