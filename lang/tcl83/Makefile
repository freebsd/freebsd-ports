# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id$
#

DISTNAME=	tcl8.0
PKGNAME=	tcl-8.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jkh@freebsd.org

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
