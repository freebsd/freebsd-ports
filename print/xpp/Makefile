# New ports collection makefile for:	xpp
# Date created:         23 Mar 2007
# Whom:                 Nate Lawson <njl@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xpp
PORTVERSION=	1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cups
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	njl@FreeBSD.org
COMMENT=	X11-based printer manager for CUPS

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xpp

post-configure:
	@${REINPLACE_CMD} -e 's|$$(all_includes)|-I ${PREFIX}/include|' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
