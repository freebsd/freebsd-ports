# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	textproc linux
MASTER_SITES=	CENTOS_LINUX/centos/${LINUX_DIST_VER}/cr/x86_64/Packages
SRC_DISTFILES=	# not available

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Binary port of Expat XML-parsing library (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	10.el7_3
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

.include <bsd.port.mk>
