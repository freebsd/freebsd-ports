PORTNAME=	amberfish
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	textproc databases

MAINTAINER=	nrn@etymon.com
COMMENT=	Full-text search engine with command-line interface
WWW=		https://gitlab.com/amberfish/amberfish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake
USE_GITLAB=	yes

GNU_CONFIGURE=	yes
ALL_TARGET=	all

PLIST_FILES=	bin/af \
		share/man/man1/af.1.gz \
		share/man/man3/afclose.3.gz \
		share/man/man3/afgetresultmd.3.gz \
		share/man/man3/afopen.3.gz \
		share/man/man3/afsearch.3.gz \
		share/man/man3/afsortdocid.3.gz \
		share/man/man3/afsortscore.3.gz
PORTDOCS=	amberfish.html

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_ALL_TARGET=	html

post-configure:
	${ECHO_CMD} "#define AF_VERSION \"v${DISTVERSION}\"" > ${WRKSRC}/src/backend/version.h
	${ECHO_CMD} v${DISTVERSION} > ${WRKSRC}/doc/version.adoc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/af

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/amberfish.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
