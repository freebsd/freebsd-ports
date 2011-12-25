# New ports collection makefile for:	ncdc
# Date created:				28 November 2011
# Whom:					Dmitriy Limonov
#
# $FreeBSD$
#

PORTNAME=	ncdc
PORTVERSION=	1.5
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dev.yorhel.nl/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm \
		xml2:${PORTSDIR}/textproc/libxml2

USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAN1=		ncdc.1 ncdc-gen-cert.1
PLIST_FILES=	bin/ncdc bin/ncdc-gen-cert

#force base compiler,linker flags to avoid linking to ncurses from ports
CFLAGS+=	-I/usr/include -I${LOCALBASE}/include
LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib

.include <bsd.port.mk>
