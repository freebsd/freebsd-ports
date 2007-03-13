# New ports collection makefile for:	postilion
# Date created:		20 February 1999
# Whom:			Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	postilion
PORTVERSION=	0.9.3c
PORTREVISION=	1
CATEGORIES=	mail tk83
MASTER_SITES=	http://www.postilion.org/software/Postilion/
DISTNAME=	${PORTNAME}-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail client with the NeXt look

LIB_DEPENDS=	c-client4:${PORTSDIR}/mail/cclient
RUN_DEPENDS=	${LOCALBASE}/lib/Img1.2/pkgIndex.tcl:${PORTSDIR}/graphics/libimg-tk83

USE_TK=		83
USE_TK_BUILD=	83

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
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
