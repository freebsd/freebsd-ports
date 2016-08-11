# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxinput
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXInput%20%28Kbd%20and%20amp_%20mouse%20config%29/LXInput%200.3.2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard and mouse config tool from the LXDE project

USES=		iconv gmake pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=  yes

NLS_USES=		gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
