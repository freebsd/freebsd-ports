# Ports collection Makefile for:	zclock
# Date created:				24 July 2001
# Whom:					Zack Hobson <zgh@malfunktion.net>
#
# $FreeBSD$
#

PORTNAME=	zclock
PORTVERSION=	1.0
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://zack.vpop.net/download/

MAINTAINER=	zgh@malfunktion.net

.if !defined(NOPORTDOCS)
# I am going to install the dependencies for building the Zclock html
# documentation. If you do not want to install these tools, run
# 	make NOPORTDOCS=true

# For best results (and less build warnings), install the
# GDP stylesheet:
# 	http://people.redhat.com/dcm/dsssl/gdp-both.dsl

BUILD_DEPENDS+=	db2html:${PORTSDIR}/textproc/dsssl-docbook-cygnus
.endif

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
