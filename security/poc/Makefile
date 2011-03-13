# New ports collection makefile for:	poc
# Date created:		Tue Jun 11 22:43:06 CEST 2002
# Whom:			king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	poc
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=poc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for managing passwords on smartcards

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	towitoko.2:${PORTSDIR}/devel/towitoko

PLIST_FILES=	bin/poc
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,; \
		s,^CPPFLAGS =,CPPFLAGS = ${CPPFLAGS} -I${LOCALBASE}/include," \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
