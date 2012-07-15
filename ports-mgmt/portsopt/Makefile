# New ports collection makefile for:    portsopt
# Date created:                         25 Dec 2006
# Whom:                                 Beat Gaetzi <beat@chruetertee.ch>
#
# $FreeBSD$
#

PORTNAME=	portsopt
PORTVERSION=	1.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.chruetertee.ch/files/download/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Shows WITH(OUT)-knobs of a port makefile

NO_BUILD=	yes

PLIST_FILES=	sbin/portsopt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portsopt ${PREFIX}/sbin

.include <bsd.port.mk>
