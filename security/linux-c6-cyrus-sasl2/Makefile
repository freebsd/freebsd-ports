# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	cyrus-sasl2
PORTVERSION=	2.1.23
PORTREVISION=	4
CATEGORIES=	security linux
DISTNAME=	cyrus-sasl-lib-${PORTVERSION}-${RPMVERSION}
SRC_DISTFILES=	cyrus-sasl-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer) (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	15.el6_6.2
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/cyrus-sasl-lib-${PORTVERSION}

.include <bsd.port.mk>
