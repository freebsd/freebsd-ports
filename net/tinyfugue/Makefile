# New ports collection makefile for:	tinyfugue
# Version required:	3.5a16
# Date created:		22 Mar 1996
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.1.1.1 1996/03/25 10:12:09 asami Exp $
#

DISTNAME=	tf-35a16
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://ftp.tcp.com/pub/mud/Clients/tf/ \
		ftp://ftp7.freebsd.org/pub/tf/

MAINTAINER=	mike@binghamton.edu

# Here's my cute little hack to make it use its proprietary
# program thing insteada make. :) This is probably a stupid way
# to do it so email me if you know of a better way.

USE_GMAKE=yes
GMAKE= ./unixmake

.include <bsd.port.mk>

BUILD_DEPENDS=
