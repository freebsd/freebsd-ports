# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.4
# Date created:		19 August 1995
# Whom:			peter
#
# $Id: Makefile,v 1.12 1998/01/21 02:39:56 peter Exp $
#

DISTNAME=	rdist-6.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.magnicomp.com/download/rdist/ \
		ftp://ftp.rge.com/pub/admin/rdist/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-magnicomp/download/rdist/

MAINTAINER=	peter@FreeBSD.org

# To avoid confusion with /usr/bin/rdist, you may prefer otherwise.
# Do not forget to deal with pkg/PLIST if you change this.
RDIST_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	BUILD_OPT="${CFLAGS}" BUILD_CLIENT=${RDIST_NAME}
MAN1=		${RDIST_NAME}.1
MAN8=		rdistd.8

post-install:
	@strip ${PREFIX}/bin/${RDIST_NAME}
	@strip ${PREFIX}/bin/rdistd

.include <bsd.port.mk>
