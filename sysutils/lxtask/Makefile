# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxtask
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF/lxde/LXTask%20%28task%20manager%29/LXTask%20${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lightweight desktop-independent task manager

LICENSE=	GPLv2

USES=		iconv gmake pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po src|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
