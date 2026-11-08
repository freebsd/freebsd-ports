PORTNAME=	mac_igmpproxy
DISTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	leper4@protonmail.com
COMMENT=	MAC policy to run net/igmpproxy as a non-privileged user
WWW=		https://git.sr.ht/~leper/mac_igmpproxy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix

USERS=		igmpproxy
GROUPS=		igmpproxy

SRHT_ACCOUNT=	leper
SRHT_PROJECT=	${PORTNAME}

PLIST_FILES=	${KMODDIR}/mac_igmpproxy.ko

.include <bsd.port.mk>
