# ex:ts=8
# Ports collection makefile for:  mopd
# Version required:     	  2.5.3
# Date created:			  Sun Nov 14, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	mopd-2.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/OS/NetBSD/mopd/

MAINTAINER=     obrien@FreeBSD.org

#	MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV=	DESTDIR=${PREFIX} MANDIR=/man/man NOMANCOMPRESS=true
MAN1=		mopprobe.1 moptrace.1 mopchk.1 mopa.out.1
MAN8=		mopd.8

do-configure:
	@${PERL} -pi.orig -e 's:/usr/sbin:/sbin:' ${WRKSRC}/Makefile.inc
	@${PERL} -pi.orig -e 's/MAN=/MAN8=/' ${WRKSRC}/mopd/Makefile

.include <bsd.port.mk>
