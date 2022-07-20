PORTNAME=	netmask
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://trap.mtview.ca.us/~talby/
DISTNAME=	netmask_${PORTVERSION}

MAINTAINER=	mike@urgle.com
COMMENT=	Tool for generating terse netmasks in several common formats

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
GNU_CONFIGURE=	yes
USES=		gmake

INFO=		netmask
PLIST_FILES=	bin/netmask \
		man/man1/netmask.1.gz

.include <bsd.port.mk>
