# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=		gnome-translate
PORTVERSION=		0.99
PORTREVISION=	15
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	libtranslate

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A natural language translator

LIB_DEPENDS=		translate:${PORTSDIR}/textproc/libtranslate

INSTALLS_OMF=		yes
INSTALLS_ICONS=		yes
GCONF_SCHEMAS=		gnome-translate.schemas
USES=			pathfix pkgconfig
USE_GNOME=		gnomeprefix eel2 intlhack libgnomeui
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-export-dynamic

OPTIONS_DEFINE=		LANGUAGE_DETECTION
LANGUAGE_DETECTION_DESC=	language detection
OPTIONS_DEFAULT=	LANGUAGE_DETECTION

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLANGUAGE_DETECTION}
CONFIGURE_ARGS+=	--disable-language-detection
.else
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
.endif

.include <bsd.port.post.mk>
