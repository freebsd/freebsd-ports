# Ports collection makefile for:    netatalk
# Version required:     netatalk-1.4b2
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $Id: Makefile,v 1.4 1998/01/22 11:06:40 asami Exp $
#

DISTNAME=       netatalk-1.4b2
CATEGORIES=	net print
MASTER_SITES=   ftp://terminator.rs.itd.umich.edu/unix/netatalk/

PATCH_SITES=	http://www.umich.edu/~rsug/netatalk/patches/1.4b2/
PATCHFILES=	afpd-macos8.diff afpd-bfree.diff

MAINTAINER=	stb@freebsd.org

NOMANCOMPRESS=	true
# XXX this is a hack to make the .so-included
# man pages work.

.include <bsd.port.mk>
