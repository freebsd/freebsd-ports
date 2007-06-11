# New ports collection makefile for:	rsstool
# Date created:		11 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsstool
DISTVERSION=	1.0.0rc1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	www
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read, parse, merge and write RSS and Atom feeds

USE_ICONV=	yes
USE_GNOME=	libxml2
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d;/^CFLAGS=/s|-O3||;/^CFLAGS=/s|=|+=|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
