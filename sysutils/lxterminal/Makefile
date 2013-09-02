# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	lxterminal
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lightweight terminal emulator from the LXDE project

LICENSE=	GPLv2

LIB_DEPENDS=	vte:${PORTSDIR}/x11-toolkits/vte

USES=		iconv pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		lxterminal.1

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
