# New ports collection makefile for:	pdflib
# Date created:		Wed Jan 9 12:27:54 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	4.0.1
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/pdflib/download/

MAINTAINER=	sysadmin@alexdupre.com

RESTRICTED=	"many odd restrictions on usage and distribution"
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-cxx

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
