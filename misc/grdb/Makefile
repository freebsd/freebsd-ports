# New ports collection makefile for:   grdb
# Date created:        13 June 2000
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	grdb
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	http://www.win.tue.nl/~stijn/grdb/

MAINTAINER=	stijn@win.tue.nl
COMMENT=	Matches Motif/Athena/Tk widgets with the current GTK theme

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomehack gnomelibs
PKGNAMESUFFIX=	-gnome
PLIST_SUB=	DATADIR="share/gnome"
.else
CONFIGURE_ARGS=	--disable-gnome
PLIST_SUB=	DATADIR="share"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/grdb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/grdb
.endif

.include <bsd.port.post.mk>
