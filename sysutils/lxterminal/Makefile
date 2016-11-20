# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxterminal
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight terminal emulator from the LXDE project

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libvte.so:x11-toolkits/vte

USES=		gmake iconv pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README
INSTALLS_ICONS=	YES

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
