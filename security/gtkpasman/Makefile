# Created by: Philippe Rocques <phil@teaser.fr>
# $FreeBSD$

PORTNAME=	gtkpasman
PORTVERSION=	0.12
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ passwords manager for system and network administrators

RUN_DEPENDS+=	gpgv2:${PORTSDIR}/security/gnupg

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk2
USE_XZ=		yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		README data/gpasman4.sample
PLIST_FILES=	bin/gtkpasman share/applications/gtkpasman.desktop

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README gpasman4.sample
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/src/Makefile.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkpasman ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/gtkpasman.desktop \
		${PREFIX}/share/applications
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
