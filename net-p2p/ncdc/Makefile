# New ports collection makefile for:	ncdc
# Date created:				28 November 2011
# Whom:					Dmitriy Limonov
#
# $FreeBSD$
#

PORTNAME=	ncdc
PORTVERSION=	1.8
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://dev.yorhel.nl/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3 \
		xml2:${PORTSDIR}/textproc/libxml2

OPTIONS=	GDBM "Build ncdc-db-upgrade" off

USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAN1=		ncdc.1 ncdc-gen-cert.1
PLIST_FILES=	bin/ncdc bin/ncdc-gen-cert

#force base compiler,linker flags to avoid linking to ncurses from ports
CFLAGS+=	-I/usr/include -I${LOCALBASE}/include
LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
PLIST_FILES+=	bin/ncdc-db-upgrade
MAN1+=		ncdc-db-upgrade.1
.endif

post-patch:
.if defined(WITHOUT_GDBM)
	@${REINPLACE_CMD} \
		-e '/have_gdbm=yes/d' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
