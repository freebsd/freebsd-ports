# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fpm2
PORTVERSION=	0.79
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://als.regnet.cz/fpm2/download

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Program that allows you to securely store the passwords

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake localbase pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

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

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|USE_NLS=yes|USE_NLS=no|' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
