# New ports collection makefile for:	cucipop
# Date created:		7 Jun 1997
# Whom:			igor@zynaps.ru
#
# $FreeBSD$
#
# NOTE: APOP works only for virtual hosts as designed!
#       Virtual hosts works only with Berkeley DB2.
#       Berkeley DB2 is in conflict with libc, so commented out. :-(

PORTNAME=	cucipop
PORTVERSION=	1.31
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://ftp.pasta.cs.uit.no/pub/IPv6/misc/
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cubic Circle's POP3 daemon (fully RFC1939 compliant)

#BUILD_DEPENDS=  ${PREFIX}/include/db2/db.h:${PORTSDIR}/databases/db2

MAN8=		cucipop.8 #makevpopdb.8
PLIST_FILES=	libexec/cucipop

.include <bsd.port.mk>
