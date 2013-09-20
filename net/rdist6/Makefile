# Created by: peter
# $FreeBSD$

PORTNAME=	rdist
PORTVERSION=	6.1.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.magnicomp.com/download/rdist/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-magnicomp/download/rdist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network file distribution/synchronisation utility

# To avoid confusion with /usr/bin/rdist, you may prefer otherwise.
RDIST_NAME?=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV=	BUILD_OPT="${CFLAGS}" BUILD_CLIENT=${RDIST_NAME}
MAN1=		${RDIST_NAME}.1
MAN8=		rdistd.8
PLIST_SUB=	RDIST_NAME=${RDIST_NAME}

NO_STAGE=	yes
post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${RDIST_NAME}
	@${STRIP_CMD} ${PREFIX}/bin/rdistd

.include <bsd.port.mk>
