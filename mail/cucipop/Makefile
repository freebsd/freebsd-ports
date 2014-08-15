# Created by: igor@zynaps.ru
# $FreeBSD$

# NOTE: APOP works only for virtual hosts as designed!
#       Virtual hosts works only with Berkeley DB2.
#       Berkeley DB2 is in conflict with libc, so commented out. :-(

PORTNAME=	cucipop
PORTVERSION=	1.31
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/ \
		http://ftp.riken.go.jp/archives/net/mail/pop/cucipop/ \
		http://horms.net/projects/cucipop/download/

PATCH_SITES=	${MASTER_SITE_RINGSERVER}
PATCH_SITE_SUBDIR=	net/kame/misc
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cubic Circle POP3 daemon (fully RFC1939 compliant)

.include <bsd.port.mk>
