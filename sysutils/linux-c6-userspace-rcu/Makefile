# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	userspace-rcu
PORTVERSION=	0.7.7
DISTVERSIONSUFFIX=	-1.el6
CATEGORIES=	sysutils linux
MASTER_SITES=	EPEL/u

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Userspace read-copy-update (RCU) data synchronization library (CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../liburcu/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
