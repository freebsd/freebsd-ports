# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adapta-backgrounds
PORTVERSION=	0.5.2.3
CATEGORIES=	x11-themes

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wallpaper collection for adapta-project

LICENSE=	GPLv2 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSE_CC_BY_SA4
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

DOCS_MAKE_ENV=	ADAPTA_BG_DOCS=yes

GH_ACCOUNT=	adapta-project
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes

USES=		autoreconf gmake gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20 libxml2

.include <bsd.port.mk>
