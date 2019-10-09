# $FreeBSD$

PORTNAME=	dtcp
PORTVERSION=	20130602
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-dbm>0:databases/rubygem-dbm
.if defined(WITH_QPOPAUTH)
RUN_DEPENDS+=	qpopauth:mail/qpopper
.endif

USES=		uidfix
USE_RC_SUBR=	dtcpc dtcps
USE_RUBY=	yes
MAKE_ENV+=	RUBY=${RUBY}

SUB_LIST+=	RUBY=${RUBY}

PLIST_FILES=	sbin/dtcpauth sbin/dtcpc sbin/dtcps \
		man/man8/dtcpauth.8.gz man/man8/dtcpc.8.gz \
		man/man8/dtcps.8.gz

.include <bsd.port.mk>
