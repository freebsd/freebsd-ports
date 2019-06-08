# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.3
DISTVERSIONSUFFIX=	-12.el7_6.2
PORTREVISION=	3
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	openssl
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
