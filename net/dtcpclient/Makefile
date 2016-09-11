# $FreeBSD$

PORTNAME=	dtcpclient
PORTVERSION=	20151002
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol client

LICENSE=	BSD2CLAUSE

USES=		ssl uidfix
USE_RC_SUBR=	dtcpclient
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	man/man8/dtcpclient.8.gz \
		sbin/dtcpclient \
		"@sample %%EXAMPLESDIR%%/dtcpclient.script etc/dtcpclient.script"

.include <bsd.port.mk>
