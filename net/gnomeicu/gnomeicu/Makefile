# Ports collection Makefile for:	GnomeICU
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomeicu2
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnomeicu
DISTNAME=	gnomeicu-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME2 ICQ client

LIB_DEPENDS+=	gnet-glib2.7:${PORTSDIR}/net/gnet-glib2 \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libglade2 gnomepanel libxml2
USE_GMAKE=		yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's|gnet|gnet-glib2|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|GNOME_PARAM_GNOME_DATADIR|GNOME_PARAM_APP_DATADIR|g' \
		${WRKSRC}/src/gnomeicu.c

.include <bsd.port.mk>
