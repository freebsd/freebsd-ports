# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	security linux
MASTER_SITES=	CENTOS_LINUX/centos/${LINUX_DIST_VER}/cr/x86_64/Packages
SRC_DISTFILES=	# not available

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Crypto library based on code used in GnuPG (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

LICENSE=	LGPL21+

RPMVERSION=	13.el7_3.1
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PORTDOCS=	AUTHORS COPYING.LIB NEWS THANKS
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
