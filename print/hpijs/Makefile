# New ports collection makefile for:	hpijs
# Date created:		1 May 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hpijs
PORTVERSION=	1.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hpinkjet

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-dependency-tracking

.if defined(WITH_CUPS)
WITH_FOOMATIC=		yes
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=	--enable-cups-install
PLIST_SUB+=		CUPS=""
.else
CONFIGURE_ARGS+=	--disable-cups-install
PLIST_SUB+=		CUPS="@comment "
.endif

.if defined(WITH_FOOMATIC)
USE_PERL5=		true
CONFIGURE_ARGS+=	--enable-foomatic-install
PLIST_SUB+=		FOOMATIC=""
.else
CONFIGURE_ARGS+=	--disable-foomatic-install
PLIST_SUB+=		FOOMATIC="@comment "
.endif

.if !defined(WITH_FOOMATIC) || !defined(WITH_CUPS)
pre-extract:
	@${ECHO_MSG} "**************************************************************"
	@${ECHO_MSG} "You can set the following build option(s):"
	@${ECHO_MSG}
.if !defined(WITH_CUPS)
	@${ECHO_MSG} "WITH_CUPS=yes	install support for cups; sets WITH_FOOMATIC"
.endif
.if !defined(WITH_FOOMATIC)
	@${ECHO_MSG} "WITH_FOOMATIC=yes	install foomatic-rip and ppd files"
.endif
	@${ECHO_MSG} "**************************************************************"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-O2 -Wall"|CFLAGS="\$$CFLAGS"|g ; \
		s|CXXFLAGS="-O2 -Wall"|CXXFLAGS="\$$CXXFLAGS"|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|cp -ax|${INSTALL_DATA}|g' ${WRKSRC}/Makefile.in

.if !defined(WITH_FOOMATIC)
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${PREFIX}/bin
.else
INSTALL_TARGET=	install-exec install-foomatic
.if defined(WITH_CUPS)
INSTALL_TARGET+=	install-cups
.endif
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
