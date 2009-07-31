# New ports collection makefile for: 	tsclient
# Date created:				01 Mar 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	tsclient
PORTVERSION=	0.150
PORTREVISION=	5
CATEGORIES=	net gnome
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	A GNOME 2 frontend for rdesktop and vncviewer

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

OPTIONS=	GNOME		"Build with gnome support" on \
		TIGHTVNC	"vncviewer support" off \
		XNEST		"X via Xnest support (experimental)" off

USE_AUTOTOOLS=	libtool:15 automake:19 autoconf:262
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="`pkg-config --libs libgnomeui-2.0`"

MAN1=		tsclient.1
PORTDOCS=	COPYING NEWS README

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
USE_GNOME+=	gnomeprefix gnomehack gnomepanel libgnomeui 
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if defined(WITH_TIGHTVNC)
RUN_DEPENDS+=	vncviewer:${PORTSDIR}/net/tightvnc
.endif

.if defined(WITH_XNEST)
RUN_DEPENDS+=	Xnest:${X_NESTSERVER_PORT}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^man1dir *=/ s,datadir,prefix,g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/aclocal.m4

post-install:
	@${LN} -sf ${PREFIX}/share/pixmaps/tsclient/tsclient.png \
		${PREFIX}/share/pixmaps/tsclient.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
