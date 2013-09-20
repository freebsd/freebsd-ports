# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	portdowngrade
PORTVERSION=	1.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sets a port back to a previous version

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

NO_BUILD=	yes
PLIST_FILES=	sbin/portdowngrade

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
