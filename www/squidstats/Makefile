# Created by: Adrian Chadd <adrian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidstats
PORTVERSION=	54
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	squidstats-r${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of simple statistical analysis bits for Squid

RUN_DEPENDS=	p5-Config-IniFiles>=2.39:devel/p5-Config-IniFiles \
		p5-RRD-Simple>=1.44:databases/p5-RRD-Simple \
		p5-SNMP_Session>=1.11:net-mgmt/p5-SNMP_Session

USES=		perl5 shebangfix
SHEBANG_FILES=	graph/src/stats.pl.in \
		graph/src/graph-summary.cgi.in

USERS=		squid
GROUPS=		squid
PLIST_SUB+=	WWWOWN=${WWWOWN} SQUID_USER=${USERS}
NO_ARCH=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
