# New ports collection makefile for: 	tsclient
# Date created:				01 Mar 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	tsclient
PORTVERSION=	0.132
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomepro.com/tsclient/

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	A GNOME 2 frontend for rdesktop and vncviewer

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

.ifdef (WITH_TIGHTVNC)
RUN_DEPENDS+=	tightvnc:${PORTSDIR}/net/tightvnc
.endif

.ifdef (WITH_XNEST)
RUN_DEPENDS+=	Xnest:${X_NESTSERVER_PORT}
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		tsclient.1

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   set WITH_TIGHTVNC for vncviewer support"
	@${ECHO_MSG} "   set WITH_XNEST for X via Xnest support (experimental)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/configure

post-install:
	@${LN} -sf ${PREFIX}/share/gnome/pixmaps/tsclient/tsclient.png \
		${PREFIX}/share/gnome/pixmaps/tsclient.png

.include <bsd.port.mk>
