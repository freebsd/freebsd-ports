# ex:ts=8
# Ports collection makefile for:  tcplist
# Version required:     	  2.1
# Date created:			  Mon Apr 14, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.2 1997/04/24 16:31:42 obrien Exp $
#

DISTNAME=	tcplist-2.2
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.cdf.toronto.edu/pub/tcplist/  \
		ftp://ftp.ece.uc.edu/pub/sun-faq/FAQs/mirrors/ftp.cdf.toronto.edu/tcplist/  \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/sun/sun-faq/FAQs/mirrors/ftp.cdf.toronto.edu/tcplist/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=     obrien@NUXI.com

RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install install.man
MAN1=		tcplist.1

.include <bsd.port.mk>
