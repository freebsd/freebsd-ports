PORTNAME=	clearlooks-themes-extras
PORTVERSION=	0.6
PORTREVISION=	8
CATEGORIES=	x11-themes
MASTER_SITES=	LOCAL/laszlof
DISTNAME=	Clearlooks-Big_Pack-${PORTVERSION}.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extras colour schemes for Clearlooks engine theme

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		gnome
USE_GNOME=	gtk20

THEME_DIR=	${PREFIX}/share/themes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc) || defined(WITH_GTKENGINE)
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:x11-themes/gtk-engines2
.else
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libclearlooks.so:x11-themes/clearlooks
.endif

do-install:
	${MKDIR} ${STAGEDIR}${THEME_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Clearlooks\* ${STAGEDIR}${THEME_DIR}

.include <bsd.port.post.mk>
