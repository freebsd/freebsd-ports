PORTNAME=	dtcp
PORTVERSION=	20130602
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client
WWW=		https://www.mahoroba.org/~ume/dtcp/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-dbm>0:databases/rubygem-dbm
.if defined(WITH_QPOPAUTH)
RUN_DEPENDS+=	qpopauth:mail/qpopper
.endif

USES=		ruby uidfix
USE_RC_SUBR=	dtcpc dtcps
MAKE_ENV+=	RUBY=${RUBY}

SUB_LIST+=	RUBY=${RUBY}

PLIST_FILES=	sbin/dtcpauth sbin/dtcpc sbin/dtcps \
		share/man/man8/dtcpauth.8.gz share/man/man8/dtcpc.8.gz \
		share/man/man8/dtcps.8.gz

.include <bsd.port.mk>
