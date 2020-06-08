# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	pdflib
PORTVERSION=	7.0.5
PORTREVISION=	6
CATEGORIES=	print perl5 java
MASTER_SITES=	LOCAL/ale
DISTNAME=	PDFlib-Lite-${PORTVERSION}p3

MAINTAINER=	ale@FreeBSD.org
COMMENT=	C library for dynamically generating PDF

BUILD_DEPENDS=	gsed:textproc/gsed

RESTRICTED=	Many odd restrictions on usage and distribution

OPTIONS_DEFINE=	PERL JAVA DOCS
PERL_DESC=	Build perl bindings
JAVA_DESC=	Build Java bindings

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-py=no --with-ruby=no --with-tcl=no

PORTDOCS=	*

PERL_USES=	perl5

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPERL}
PLIST_SUB+=	PERL=""
CONFIGURE_ARGS+=--with-perl=${PERL}
.else
CONFIGURE_ARGS+=--with-perl=no
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
PLIST_SUB+=	JAVA=""
CONFIGURE_ARGS+=--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=--with-java=no
PLIST_SUB+=	JAVA="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdfimage ${STAGEDIR}${PREFIX}/bin/text2pdf \
		${STAGEDIR}${PREFIX}/lib/libpdf.so.6.0.5
	${MKDIR} ${STAGEDIR}${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/* ${STAGEDIR}${DATADIR}/fonts

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pdflib/* ${STAGEDIR}${DOCSDIR}

post-install-JAVA-on:
	${INSTALL_DATA} ${WRKSRC}/bind/pdflib/java/pdflib.jar ${STAGEDIR}${JAVAJARDIR}/pdflib.jar

.include <bsd.port.post.mk>
