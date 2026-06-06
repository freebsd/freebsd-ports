PORTNAME=	bone-kmods
DISTVERSION=	2026.05.16
CATEGORIES=	net

MAINTAINER=	dave@freedave.net
COMMENT=	Collection of netgraph kernel modules ${COMMENT_${FLAVOR}}
WWW=		https://github.com/dmarker/bone

LICENSE=	BSD2CLAUSE

# Patches are available here:
# https://github.com/dmarker/bong-patches/tree/main/14-stable
# but there is no plan to merge those.
BROKEN_FreeBSD_14=	requires additional patches

# solving same issue as bug 286717 with FLAVORS
FLAVORS=	default invariants
FLAVOR?=	${FLAVORS:[1]}

default_CONFLICTS_INSTALL=	${PORTNAME}-invariants
invariants_PKGNAMESUFFIX=	-invariants
invariants_CONFLICTS_INSTALL=	${PORTNAME}
COMMENT_invariants=	(invariants kernel)

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	dmarker
GH_PROJECT=	bone

MAKEFILE=	Makefile.kmods

.if ${FLAVOR:U} == invariants
CFLAGS+=	-DINVARIANT_SUPPORT -DINVARIANTS
.endif

PLIST_FILES=	${KMODDIR}/ng_pcap.ko \
		${KMODDIR}/ng_ula4tag.ko \
		${KMODDIR}/ng_wormhole.ko \
		include/netgraph/ng_pcap.h \
		include/netgraph/ng_ula4tag.h \
		include/netgraph/ng_wormhole.h \
		share/man/man4/ng_pcap.4.gz \
		share/man/man4/ng_ula4tag.4.gz \
		share/man/man4/ng_wormhole.4.gz

.include <bsd.port.mk>
