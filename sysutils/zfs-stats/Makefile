# New ports collection makefile for:	zfs-stats
# Date created:		2010-10-20
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zfs-stats
PORTVERSION=	1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/mmatuska/zfs-stats/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Display human-readable ZFS statistics

LICENSE=	BSD

USES=		perl5

NO_BUILD=	yes

PLIST_FILES=	bin/zfs-stats \
		bin/zfs-mon

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/env -iS perl|${PERL}|g" ${WRKSRC}/zfs-stats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-stats ${PREFIX}/bin/zfs-stats
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-mon ${PREFIX}/bin/zfs-mon

.include <bsd.port.mk>
