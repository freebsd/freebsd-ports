# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.3 1997/11/26 22:48:50 pst Exp $
#

DISTNAME=	tcl8.0p2
PKGNAME=	tcl-8.0.2
CATEGORIES=	lang tcl80
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jkh@freebsd.org

WRKSRC=		${WRKDIR}/tcl8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
