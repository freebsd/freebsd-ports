# New ports collection makefile for: netscape (navigator only)
# Date created:		20 Sept 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
MASTER_SITES=	ftp://ftp.netscape.com./pub/communicator/english/4.72/unix/unsupported/freebsd/navigator_standalone/
DISTFILES=	navigator-v472-export.x86-unknown-freebsd.tar.gz
.elif ${ARCH} == "alpha"
MASTER_SITES=	ftp://ftp.netscape.com./pub/communicator/english/4.72/unix/supported/dec_unix40/navigator_standalone/
DISTFILES=	navigator-v472-export.alpha-dec-osf4.0.tar.gz
.endif

ONLY_FOR_ARCHS=	i386 alpha

BROWSER=	navigator
INFILE_HEAD=	'Navigator,4.72.0.20000131'

PRE_MK_INCLUDED=	yes
.include "${.CURDIR}/../netscape47-communicator/Makefile"
