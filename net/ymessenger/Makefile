# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	0.93.0
CATEGORIES=	net
MASTER_SITES=	http://download.yahoo.com/dl/unix/fbsd4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	LoRd_CJ@dalusers.com

USE_GTK=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/bin/ymessenger ${PREFIX}/bin

.include <bsd.port.mk>
