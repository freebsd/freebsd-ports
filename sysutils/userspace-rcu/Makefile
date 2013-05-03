# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	userspace-rcu
PORTVERSION=	0.7.5
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	A read-copy-update data synchronization library

LICENSE=	LGPL21

PORTDOCS=	ChangeLog README cds-api.txt rcu-api.txt uatomic-api.txt

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

.include <bsd.port.mk>
