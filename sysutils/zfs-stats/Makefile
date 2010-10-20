# New ports collection makefile for:	zfs-stats
# Date created:		2010-10-20
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zfs-stats
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vx.sk/zfs-stats/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Display human-readable ZFS statistics

USE_PERL5=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/zfs-stats

OPTIONS=	HUMAN_BYTES	"Depend on Number::Bytes::Human"	off

.include <bsd.port.options.mk>

.if defined(WITH_HUMAN_BYTES)
RUN_DEPENDS+=	p5-Number-Bytes-Human>0:${PORTSDIR}/devel/p5-Number-Bytes-Human
.endif

do-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/bin/perl|${PERL}|g" ${WRKSRC}/zfs-stats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-stats ${PREFIX}/bin/zfs-stats

.include <bsd.port.mk>
