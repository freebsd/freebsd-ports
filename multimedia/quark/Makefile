# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	quark
PORTVERSION=	3.24
PORTREVISION=	6
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://hsgg.github.com/quark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio player, for geeks, by geeks

LICENSE=	GPLv2

LIB_DEPENDS=	libxine.so:multimedia/libxine

USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomevfs2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS COPYING INSTALL README
GCONF_SCHEMAS=	quark.schemas strange-quark.schemas

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-g |CFLAGS="$$CFLAGS |g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
