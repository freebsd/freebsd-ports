PORTNAME=	himitsu-keyring
DISTVERSION=	0.2.0
CATEGORIES=	security python
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	keyring-${DISTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	GTK4-based prompter implementation for Himitsu
WWW=		https://himitsustore.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy

USES=		desktop-file-utils gnome meson pkgconfig python
USE_GNOME=	glib20 gtk-update-icon-cache

NO_ARCH=	yes

SRHT_ACCOUNT=	martijnbraam
SRHT_PROJECT=	keyring

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/himitsu_gtk/meson.build

.include <bsd.port.mk>
