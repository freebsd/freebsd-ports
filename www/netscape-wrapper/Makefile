# New ports collection makefile for:	netscape-wrapper
# Date created:		3 May 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	netscape-wrapper
PORTVERSION=	2000.07.07
CATEGORIES=	www
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Netscape wrapper to avoid multiple invocation and more

RUN_DEPENDS=	netscape-remote:${PORTSDIR}/www/netscape-remote

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/netscape

do-build:
	${SED} 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/netscape.sh > ${WRKSRC}/netscape.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/netscape.sh ${PREFIX}/bin/netscape

.include <bsd.port.mk>
