# New ports collection makefile for:	hpijs
# Date created:		1 May 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hpijs
PORTVERSION=	1.6.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hpinkjet

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-cups-install --disable-foomatic-install

PORTDOCS=	gs_hpijs.png hpijs_readme.html
PLIST_FILES=	bin/hpijs

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-O2 -Wall"|CFLAGS="\$$CFLAGS"|g ; \
		 s|CXXFLAGS="-O2 -Wall"|CXXFLAGS="\$$CXXFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| ijs.[cho]||g ; \
		 s| ijs_client.h||g ; \
		 s| ijs_server.[cho]||g ; \
		 s| ijs_exec_unix.[co]||g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
