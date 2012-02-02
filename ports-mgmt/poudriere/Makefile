# New ports collection makefile for:	poudriere
# Date created:		2012-01-31
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poudriere
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://files.etoilebsd.net/poudriere/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

NO_BUILD=	yes
MANCOMPRESSED=	yes
MAN8=	poudriere.8

PLIST_FILES=	etc/poudriere.conf.sample \
		bin/poudriere \
		share/poudriere/common.sh \
		share/poudriere/test_ports.sh \
		share/poudriere/ports.sh \
		share/poudriere/jail.sh \
		share/poudriere/bulk.sh
PLIST_DIRS=	share/poudriere

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/poudriere.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
