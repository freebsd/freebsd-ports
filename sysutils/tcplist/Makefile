# ex:ts=8
# Ports collection makefile for:  tcplist
# Date created:			  Mon Apr 14, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	tcplist
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.cdf.toronto.edu/pub/jdd/tcplist/
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists tcp connections to/from local machine (+username on both sides)

RUN_DEPENDS=	${LOCALBASE}/sbin/lsof:${PORTSDIR}/sysutils/lsof

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install install.man
MAN1=		tcplist.1

.include <bsd.port.mk>
