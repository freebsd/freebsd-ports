# New ports collection makefile for:	netscape-wrapper
# Date created:		3 May 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	netscape-wrapper
PORTVERSION=	2000.05.07
CATEGORIES=	www
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	netscape-remote:${PORTSDIR}/www/netscape-remote

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/netscape.sh ${PREFIX}/bin/netscape

.include <bsd.port.mk>
