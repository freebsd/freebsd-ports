# New ports collection makefile for:	hpijs
# Date created:		1 May 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hpijs
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hpinkjet
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The drivers and support resources for the HP Inkjet Printers

LIB_DEPENDS=	ijs.1:${PORTSDIR}/print/libijs

IJS_CONFIG?=	${LOCALBASE}/bin/ijs-config

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	`${IJS_CONFIG} --cflags` -DHAVE_INTTYPES_H=1
LDFLAGS=	`${IJS_CONFIG} --libs`

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-O2 -Wall"|CFLAGS="\$$CFLAGS"|g ; \
		 s|CXXFLAGS="-O2 -Wall"|CXXFLAGS="\$$CXXFLAGS"|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| ijs.[cho]||g ; \
		 s| ijs_client.h||g ; \
		 s| ijs_server.[cho]||g ; \
		 s| ijs_exec_unix.[co]||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' ${WRKSRC}/platform.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
