# New ports collection makefile for:	pdflib
# Date created:		Wed Jan 9 12:27:54 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	5.0.1
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/products/pdflib/download/
DISTNAME=	PDFlib-Lite-${PORTVERSION}-Unix-src

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A C library for dynamically generating PDF

RESTRICTED=	"many odd restrictions on usage and distribution"

LATEST_LINK?=	${PORTNAME}
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=no \
		--with-py=no \
		--with-tcl=no

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB=	PERL=""
CONFIGURE_ARGS+=--with-perl=${PERL}
PKGNAMESUFFIX=	-perl
.else
CONFIGURE_ARGS+=--with-perl=no
PLIST_SUB=	PERL="@comment "
.endif

post-install:
	${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/* ${DATADIR}/fonts
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pdflib/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
