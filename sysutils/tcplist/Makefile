# ex:ts=8
# Ports collection makefile for:  tcplist
# Version required:     	  2.1
# Date created:			  Mon Apr 14, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.4 1997/07/21 00:37:11 fenner Exp $
#

DISTNAME=	tcplist-2.2
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.cdf.toronto.edu/pub/jdd/tcplist/
EXTRACT_SUFX=	.shar

MAINTAINER=     obrien@NUXI.com

RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

EXTRACT_CMD=	cat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install install.man
MAN1=		tcplist.1

.include <bsd.port.mk>
