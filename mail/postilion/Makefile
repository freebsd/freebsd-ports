# New ports collection makefile for:	postilion
# Date created:		20 February 1999
# Whom:			Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	postilion
PORTVERSION=	0.9.3c
CATEGORIES=	mail tk83
MASTER_SITES=	http://www.postilion.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail client with the NeXt look

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		c-client4:${PORTSDIR}/mail/cclient
RUN_DEPENDS=	${LOCALBASE}/lib/Img1.2/pkgIndex.tcl:${PORTSDIR}/graphics/libimg
BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS=	PORTVERSION="${PORTVERSION}" LOCALBASE="${LOCALBASE}" \
		MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" \
		DIR=lib/postilionlib SED="${SED}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude '*/imap/*'

do-configure:
	${LN} -s ${FILESDIR}/config.h ${WRKSRC}

.include <bsd.port.mk>
