PORTNAME=	hiprompt-gtk
DISTVERSION=	0.10
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	GTK4-based prompter implementation for Himitsu
WWW=		https://himitsustore.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hare-adwaita>=0:devel/hare-adwaita \
		hare-gi>=0:devel/hare-gi \
		hare-gtk4-layer-shell>=0:devel/hare-gtk4-layer-shell \
		hare-lang>=0:devel/hare \
		himitsu>=0:security/himitsu
RUN_DEPENDS=	hare-adwaita>=0:devel/hare-adwaita \
		hare-gi>=0:devel/hare-gi \
		hare-gtk4-layer-shell>=0:devel/hare-gtk4-layer-shell \
		himitsu>=0:security/himitsu

USES=		gettext-runtime gmake pkgconfig

MAKE_ARGS=	DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX}
ALL_TARGET=	hiprompt-gtk

PLIST_FILES=	bin/hiprompt-gtk

SRHT_ACCOUNT=	sircmpwn
SRHT_PROJECT=	${PORTNAME}

.include <bsd.port.mk>
