# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	cyrus-sasl2
PORTVERSION=	2.1.23
PORTREVISION=	3
CATEGORIES=	security linux
DISTNAME=	cyrus-sasl-lib-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer) (Linux CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	i386 amd64

SRC_DISTFILES= cyrus-sasl-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	15.el6_6.2
USE_LDCONFIG=	yes
BRANDELF_FILES=	usr/sbin/sasldblistusers2 usr/sbin/saslpasswd2
DESCR=	${.CURDIR}/../cyrus-sasl2/pkg-descr

DOCSDIR=	usr/share/doc/cyrus-sasl-lib-${PORTVERSION}

.include <bsd.port.mk>
