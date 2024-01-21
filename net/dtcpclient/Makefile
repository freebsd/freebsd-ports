PORTNAME=	dtcpclient
PORTVERSION=	20151002
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol client
WWW=		https://www.mahoroba.org/~ume/dtcp/

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_RC_SUBR=	dtcpclient

PLIST_FILES=	share/man/man8/dtcpclient.8.gz \
		sbin/dtcpclient \
		"@sample %%EXAMPLESDIR%%/dtcpclient.script etc/dtcpclient.script"

.include <bsd.port.mk>
