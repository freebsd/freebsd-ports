# New ports collection makefile for:	tcl8.1
# Version required:	8.1.a1
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.4 1997/12/01 16:50:49 pst Exp $
#

DISTNAME=	tcl8.1a1
PKGNAME=	tcl-8.1.a1
CATEGORIES=	lang tcl81
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jseger@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
