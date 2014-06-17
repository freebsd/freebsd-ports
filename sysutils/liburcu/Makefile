# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	liburcu
PORTVERSION=	0.7.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${PORTVERSION}

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Userspace read-copy-update (RCU) data synchronization library

LICENSE=	LGPL21

PORTDOCS=	ChangeLog README cds-api.txt rcu-api.txt uatomic-api.txt

USES=		pathfix libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
