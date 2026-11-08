PORTNAME=	if_pair
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.1
CATEGORIES=	net
PKGNAMESUFFIX=	-kmod

MAINTAINER=	crest@rlwinm.de
COMMENT=	Fast IP point to point interface between FreeBSD vnet jails

LICENSE=	BSD2CLAUSE

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	Crest

PLIST_FILES=	${KMODDIR}/if_pair.ko \
		share/man/man4/if_pair.4.gz \
		share/man/man4/pair.4.gz

.include <bsd.port.mk>
