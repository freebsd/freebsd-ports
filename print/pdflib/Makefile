PORTNAME=	pdflib
PORTVERSION=	7.0.5
PORTREVISION=	6
CATEGORIES=	print perl5 java
MASTER_SITES=	LOCAL/ale:src	\
		LOCAL/crees:license
DISTNAME=	PDFlib-Lite-${PORTVERSION}p3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src PDFlib-Lite-license.txt.gz:license
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	C library for dynamically generating PDF

LICENSE=	PDFlib-Lite
LICENSE_NAME=	PDFlib-Lite
LICENSE_FILE=	${WRKDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		cpe gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-py=no --with-ruby=no --with-tcl=no

OPTIONS_DEFINE=	PERL JAVA DOCS
OPTIONS_SUB=	yes
PERL_DESC=	Build perl bindings
JAVA_DESC=	Build Java bindings
PERL_CONFIGURE_WITH=	perl=${PERL}

PORTDOCS=	*

PERL_USES=	perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
CONFIGURE_ARGS+=--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=--with-java=no
.endif

post-extract:
	${GZCAT} ${DISTDIR}/PDFlib-Lite-license.txt.gz > ${WRKDIR}/LICENSE

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

.include <bsd.port.mk>
