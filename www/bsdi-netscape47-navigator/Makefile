# New ports collection makefile for: netscape (navigator only)
# Date created:		20 Sept 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME?=	netscape-${BROWSER_ARC}
PORTVERSION?=	${BROWSER_VER}

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

.if ${ARCH} == "i386"
MASTER_SITES=	ftp://ftp.netscape.com./pub/communicator/english/4.73/unix/unsupported/freebsd/navigator_standalone/
DISTFILES=	navigator-v473-export.x86-unknown-freebsd.tar.gz
.elif ${ARCH} == "alpha"
MASTER_SITES=	ftp://ftp.netscape.com./pub/communicator/english/4.73/unix/supported/dec_unix40/navigator_standalone/
DISTFILES=	navigator-v473-export.alpha-dec-osf4.0.tar.gz
.endif

BROWSER=	navigator
INFILE_HEAD=	'Navigator,4.73.0.20000502'

.include "${.CURDIR}/../netscape47-communicator/Makefile"
