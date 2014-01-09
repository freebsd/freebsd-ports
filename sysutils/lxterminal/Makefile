# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxterminal
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lightweight terminal emulator from the LXDE project

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libvte.so:${PORTSDIR}/x11-toolkits/vte

USES=		gmake iconv pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
