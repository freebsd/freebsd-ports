# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxtask
PORTVERSION=	0.1.4
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF/lxde/LXTask%20%28task%20manager%29/LXTask%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight desktop-independent task manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome iconv pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext localbase
NLS_USES_OFF=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po src|src|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
