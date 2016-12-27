# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mrouted
PORTVERSION=	3.9.7
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Multicast routing daemon providing DVMRP for IPv4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_RC_SUBR=	mrouted
GH_ACCOUNT=	troglobit
HAS_CONFIGURE=	yes
MAKE_ARGS=	sysconfdir="${PREFIX}/etc" \
		mandir="${MAN8PREFIX}/man/man8"
PORTDOCS=	README AUTHORS ChangeLog
PLIST_FILES=	sbin/map-mbone sbin/mrouted sbin/mrinfo sbin/mtrace \
		etc/mrouted.conf man/man8/map-mbone.8.gz \
		man/man8/mrinfo.8.gz man/man8/mrouted.8.gz \
		man/man8/mtrace.8.gz
OPTIONS_DEFINE=	DOCS
DOCS_MAKE_ARGS=	datadir="${DOCSDIR}" doc=yes

.include <bsd.port.mk>
