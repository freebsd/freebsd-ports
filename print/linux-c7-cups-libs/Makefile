# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	cups-libs
PORTVERSION=	1.6.3
CATEGORIES=	print linux
SRC_DISTFILES=	cups-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common UNIX Printing System libraries

CONFLICT=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	22.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	gnutls
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../cups/pkg-descr

.include <bsd.port.mk>
