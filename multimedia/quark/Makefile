# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	quark
PORTVERSION=	3.24
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://hsgg.github.com/quark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An audio player, for geeks, by geeks

LIB_DEPENDS=	xine.2:${PORTSDIR}/multimedia/libxine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomevfs2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib


PORTDOCS=	AUTHORS COPYING INSTALL README
GCONF_SCHEMAS=	quark.schemas strange-quark.schemas

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-g |CFLAGS="$$CFLAGS |g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
