# New ports collection makefile for:	tcl8.1
# Version required:	8.1.a2
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.7 1998/03/22 09:37:07 asami Exp $
#

DISTNAME=	tcl8.1a2
PKGNAME=	tcl-8.1.a2
CATEGORIES=	lang tcl81
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/

MAINTAINER=	jseger@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
