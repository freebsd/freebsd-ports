# Ports collection Makefile for:	GnomeICU
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomeicu
PORTVERSION=	0.93
CATEGORIES=	net gnome
MASTER_SITES=	ftp://gnomeicu.gdev.net/pub/gnomeicu/ \
		ftp://ftp.vision.net.au/ftp7/linuxberg/files/gnome/com/ \
		ftp://ftp.datacomm.ch/.3/linuxberg/files/gnome/com/ \
		ftp://ftp.proxad.net/mirrors/ftp.linuxberg.com/files/gnome/com/

MAINTAINER=	nectar@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
