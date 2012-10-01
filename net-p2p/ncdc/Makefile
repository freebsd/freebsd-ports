# Created by: Dmitriy Limonov
# $FreeBSD$

PORTNAME=	ncdc
PORTVERSION=	1.13
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://dev.yorhel.nl/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		gnutls:${PORTSDIR}/security/gnutls

OPTIONS_DEFINE=	GDBM
GDBM_DESC=	Build ncdc-db-upgrade

USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ncdc.1
PLIST_FILES=	bin/ncdc

#force base compiler,linker flags to avoid linking to ncurses from ports
CFLAGS+=	-I/usr/include -I${LOCALBASE}/include
LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=--enable-db-upgrade
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
PLIST_FILES+=	bin/ncdc-db-upgrade
MAN1+=		ncdc-db-upgrade.1
.endif

.include <bsd.port.mk>
