# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.5
# Date created:		19 August 1995
# Whom:			peter
#
# $FreeBSD$
#

DISTNAME=	rdist-6.1.5
CATEGORIES=	net
MASTER_SITES=	http://www.magnicomp.com/download/rdist/ \
		ftp://ftp.rge.com/pub/admin/rdist/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-magnicomp/download/rdist/

MAINTAINER=	peter@FreeBSD.org

.include <bsd.port.pre.mk>

# To avoid confusion with /usr/bin/rdist, you may prefer otherwise.
RDIST_NAME?=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV=	BUILD_OPT="${CFLAGS}" BUILD_CLIENT=${RDIST_NAME}
MAN1=		${RDIST_NAME}.1
MAN8=		rdistd.8
PLIST_SUB=	RDIST_NAME=${RDIST_NAME}

post-install:
	@strip ${PREFIX}/bin/${RDIST_NAME}
	@strip ${PREFIX}/bin/rdistd

.include <bsd.port.post.mk>
