# New ports collection makefile for:	tcl8.1
# Version required:	8.1.a2
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.5 1998/02/16 15:58:18 jseger Exp $
#

DISTNAME=	tcl8.1a2
PKGNAME=	tcl-8.1.a2
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
