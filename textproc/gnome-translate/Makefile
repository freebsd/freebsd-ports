# New ports collection makefile for:	gnome-translate
# Date created:			28 Jan 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		gnome-translate
PORTVERSION=		0.99
PORTREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	libtranslate

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A natural language translator

LIB_DEPENDS=		translate:${PORTSDIR}/textproc/libtranslate

INSTALLS_OMF=		yes
GCONF_SCHEMAS=		gnome-translate.schemas
USE_X_PREFIX=		yes
USE_GNOME=		gnomehack gnomeprefix eel2 intlhack
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -Wl,-export-dynamic"

OPTIONS=		LANGUAGE_DETECTION "language detection" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_LANGUAGE_DETECTION)
CONFIGURE_ARGS+=	--disable-language-detection
.else
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
.endif

.include <bsd.port.post.mk>
