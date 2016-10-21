# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	cyrus-sasl2
PORTVERSION=	2.1.26
CATEGORIES=	security linux
DISTNAME=	cyrus-sasl-lib-${PORTVERSION}-${RPMVERSION}
SRC_DISTFILES=	cyrus-sasl-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer) (Linux CentOS ${LINUX_DIST_VER})

CONFLICT=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	19.2.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/cyrus-sasl-lib-${PORTVERSION}

.include <bsd.port.mk>
