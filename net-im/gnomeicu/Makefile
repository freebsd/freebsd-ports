# Ports collection Makefile for:	GnomeICU
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#    $MCom: ports/net-im/gnomeicu/Makefile,v 1.2 2007/05/19 21:36:18 marcus Exp $

PORTNAME=	gnomeicu
PORTVERSION=	0.99.14
PORTREVISION=	3
CATEGORIES=	net-im gnome
MASTER_SITES=	SF

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 ICQ client

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gnomehack libglade2 gnomepanel libxml2 \
		intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

GCONF_SCHEMAS=	gnomeicu.schemas

.if defined(WITH_DANTE)
LIB_DEPENDS+=	socks.1:${PORTSDIR}/net/dante
SOCKSFLAGS=	-Dconnect=Rconnect -Dbind=Rbind -Dgetsockname=Rgetsockname \
		-Dgetpeername=Rgetpeername -Daccept=Raccept \
		-Drresvport=Rrresvport -Dbindresvport=Rbindresvport \
		-Dgethostbyname=Rgethostbyname \
		-Dgethostbyname2=Rgethostbyname2 -Dsendto=Rsendto \
		-Drecvfrom=Rrecvfrom -Drecvfrom=Rrecvfrom -Dwrite=Rwrite \
		-Dwritev=Rwritev -Dsend=Rsend -Dsendmsg=Rsendmsg \
		-Dread=Rread -Dreadv=Rreadv -Drecv=Rrecv -Drecvmsg=Rrecvmsg
SOCKSLIBS=	-lsocks
.elif defined(WITH_SOCKS5)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
SOCKSFLAGS=	-DSOCKS -include ${LOCALBASE}/include/socks.h
SOCKSLIBS=	-lsocks5
.endif

CONFIGURE_ARGS=	--with-statusmenu
CONFIGURE_ENV=	CPPFLAGS="${SOCKSFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-liconv ${SOCKSLIBS} -lintl" \
		CFLAGS="${CFLAGS}"

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-gtkspell
.else
CONFIGURE_ARGS+=--disable-gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|GNOME_PARAM_GNOME_DATADIR|GNOME_PARAM_APP_DATADIR|g' \
		${WRKSRC}/src/gnomeicu.c

.include <bsd.port.mk>
