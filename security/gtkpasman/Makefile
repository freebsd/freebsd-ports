# Created by: Philippe Rocques <phil@teaser.fr>
# $FreeBSD$

PORTNAME=	gtkpasman
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ passwords manager for system and network administrators

RUN_DEPENDS+=	gpgv2:security/gnupg

USES=		desktop-file-utils gettext gmake gnome pkgconfig tar:xz
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	bin/gtkpasman share/applications/gtkpasman.desktop

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/src/Makefile.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkpasman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/gtkpasman.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/data/gpasman4.sample ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
