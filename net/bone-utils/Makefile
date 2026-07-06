PORTNAME=	bone-utils
DISTVERSION=	2026.05.16
CATEGORIES=	net sysutils

MAINTAINER=	dave@freedave.net
COMMENT=	Collection of netgraph utilities for bone-kmods
WWW=		https://github.com/dmarker/bone

LICENSE=	BSD2CLAUSE

# Patches are available here:
# https://github.com/dmarker/bong-patches/tree/main/14-stable
# but there is no plan to merge those.
BROKEN_FreeBSD_14=	requires additional patches

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	dmarker
GH_PROJECT=	bone
GH_TAGNAME=	50c5a95

MAKEFILE=	Makefile.utils

PLIST_FILES=	etc/rc.d/bone_netgraph \
		bin/jeiface \
		bin/ngpcap \
		bin/ngportal \
		share/man/man8/ngportal.8.gz \
		share/man/man8/ngpcap.8.gz

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rc.d/bone_netgraph

.include <bsd.port.mk>
