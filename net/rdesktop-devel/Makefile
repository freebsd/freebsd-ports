# New ports collection makefile for:  rdesktop
# Date created:               13 December 2000
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	rdesktop
PORTVERSION=	1.2b1
CATEGORIES=	net comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	rdesktop-1.2beta1

MAINTAINER=	chris@aims.com.au

USE_XLIB=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		rdesktop.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rdesktop ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/rdesktop.1 ${PREFIX}/man/man1
	@${INSTALL} -d -v -m 755 ${PREFIX}/share/rdesktop
	@${INSTALL} -d -v -m 755 ${PREFIX}/share/rdesktop/keymaps
	@for f in ${WRKSRC}/keymaps/*; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/rdesktop/keymaps; \
	done

.include <bsd.port.mk>
