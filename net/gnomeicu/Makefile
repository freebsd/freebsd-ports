# Ports collection Makefile for:	GnomeICU
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomeicu
PORTVERSION=	0.96.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= gnomeicu

MAINTAINER=	nectar@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		iconv.2:${PORTSDIR}/converters/iconv

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
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
.endif

CONFIGURE_ARGS= --with-statusmenu
CONFIGURE_ENV=	CPPFLAGS="${SOCKSFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-liconv ${SOCKSLIBS}" \
		CFLAGS="${CFLAGS}"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
