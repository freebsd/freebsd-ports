# ex:ts=8
# Ports collection makefile for:	xbiso
# Date created:			Jan 28, 2004
# Whom:				ijliao	ij
#
# $FreeBSD$
#

PORTNAME=	xbiso
PORTVERSION=	0.6.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XBox xdvdfs iso extraction utility

LIB_DEPENDS=	ftp.3:${PORTSDIR}/ftp/ftplib

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/xbiso

post-patch:
	@${REINPLACE_CMD} -e "s,^LIBS =,LIBS+=," ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbiso ${PREFIX}/bin

.include <bsd.port.mk>
