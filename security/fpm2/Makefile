# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fpm2
PORTVERSION=	0.79
CATEGORIES=	security
MASTER_SITES=	http://als.regnet.cz/fpm2/download/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Program that allows you to securely store the passwords

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog README

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=		gettext

.include <bsd.port.options.mk>

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limit:^0.7\..*

post-configure:
	@${REINPLACE_CMD} -e \
		's|^Icon.*|Icon=${PREFIX}/share/pixmaps/${PORTNAME}/logo.png|' \
		-e 's|^Categories=.*|Categories=GTK;Utility;System;|' \
		${WRKSRC}/data/${PORTNAME}.desktop.in

post-patch:
	@${REINPLACE_CMD} -E -e "s@encrypt\(@bfishencrypt\(@g" \
		${WRKSRC}/src/blowfish.c
	@${REINPLACE_CMD} -e 's|gdk_pixbuf_unref|g_object_unref|g' \
		${WRKSRC}/src/interface.c

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|USE_NLS=yes|USE_NLS=no|' ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
