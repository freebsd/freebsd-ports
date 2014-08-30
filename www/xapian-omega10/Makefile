# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian-omega10
PORTVERSION=	1.0.23
CATEGORIES=	www
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2

BROKEN=		Fails to configure

LIB_DEPENDS=	libxapian.so:${PORTSDIR}/databases/xapian-core10

USES=		perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	run

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		omindex.1 scriptindex.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/10$//}
WWWDIR=		${PREFIX}/www/${PORTNAME:S/10$//}

MORE_PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTDOCS=	cgiparams.html omegascript.html overview.html \
		quickstart.html scriptindex.html termprefixes.html \
		${MORE_PORTDOCS}
PORTEXAMPLES=	omega.conf

OPTIONS_DEFINE=	ICONV DOCS EXAMPLES
OPTIONS_DEFAULT=	ICONV

PORTSCOUT=	limit:^1\.0\.

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=			iconv
CONFIGURE_ARGS+=	--with-iconv
LDFLAGS+=		${ICONV_LIB}
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(dist_sysconf_DATA\ =\ omega\.conf\)|#\1|' \
		-e "s|^\(pkglibbindir\)\ =.*/bin|\1\ =\ \$$(prefix)/${WWWDIR_REL}/cgi-bin|" \
		 ${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} \
		-e 's|^\(SUBDIRS\ =\ \.\) docs|\1|' \
		 ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${MORE_PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
