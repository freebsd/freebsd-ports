# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mrouted
PORTVERSION=	3.9.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/troglobit/mrouted/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Multicast routing daemon providing DVMRP for IPv4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_RC_SUBR=	mrouted
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	sysconfdir=${PREFIX}/etc \
		mandir=${MAN8PREFIX}/man/man8

MAN8=		map-mbone.8 mrouted.8 mrinfo.8 mtrace.8
PORTDOCS=	README AUTHORS ChangeLog

PLIST_FILES=	sbin/map-mbone sbin/mrouted sbin/mrinfo sbin/mtrace \
		etc/mrouted.conf

.ifdef	NOPORTDOCS
MAKE_ARGS+=	datadir=${WRKDIR}/doc
.endif

.include <bsd.port.mk>
