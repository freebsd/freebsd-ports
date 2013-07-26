# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupsc
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://heim.ifi.uio.no/~hennikul/gupsc/download/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A free Gnome client for the Network UPS Tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gnomehier
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/local|${PREFIX}|' \
			-e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
