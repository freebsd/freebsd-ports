# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	0.93.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.yahoo.com/dl/unix/fbsd4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	calle.madestrand@norrgarden.se

ONLY_FOR_ARCHS=	i386

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GTK=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/bin/ymessenger ${PREFIX}/bin

post-extract:
	echo 2 | dd bs=1 count=1 conv=notrunc seek=21653 \
		of=${WRKDIR}/bin/ymessenger
.include <bsd.port.mk>
