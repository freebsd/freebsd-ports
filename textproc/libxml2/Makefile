PORTNAME=	libxml2
PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMESUFFIX=

COMMENT=	Documentation package for XML parser library for GNOME

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		libxml2-core=${PORTVERSION}:textproc/libxml2-core \
		xsltproc:textproc/libxslt
# not an actual dependency but required to keep the many
# other ports that declare a depends on textproc/libxml2 building
LIB_DEPENDS=	libxml2.so:textproc/libxml2-core

USES=		shebangfix

DOCSDIR=	${PREFIX}/share/doc/libxml2-docs
EXAMPLESDIR=	${PREFIX}/share/examples/libxml2-docs
FILESDIR=	${.CURDIR}/files
MASTERDIR=	${.CURDIR}/../libxml2-core

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/doc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
PORTDOCS=	*

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE:NDOCS} ${OPTIONS_GROUP_LEGACY}
OPTIONS_SLAVE=		DOCS

pre-everything::
	@if ${PKG_INFO} -e ${PORTNAME} && \
	    test "<" = $$(${PKG_VERSION} -t $$(${PKG_QUERY} %v $$(${PKG_INFO} -q -O ${PORTNAME})) 2.15) ; then \
	        ${ECHO_CMD} "=== libxml2 < 2.15 detected, you must deinstall first ===" ; \
		${ECHO_CMD} "=== because you cannot install libxml2-core otherwise ===" ; \
		${ECHO_CMD} "=== In case of more trouble, try make clean-depends.  ===" ; \
		exit 1; \
	fi

post-install:
# Documentation should be in DOCSDIR
	${MKDIR} ${STAGEDIR}${DOCSDIR}/devhelp
	${MV} ${STAGEDIR}${PREFIX}/share/doc/libxml2/html/ \
		${STAGEDIR}${DOCSDIR}/devhelp
	${RM} -rv ${STAGEDIR}${PREFIX}/share/gtk-doc
	${MV} ${STAGEDIR}${PREFIX}/share/doc/libxml2 \
		${STAGEDIR}${DOCSDIR}
# Install remaining documentation that's not connected to autotools
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include "${MASTERDIR}/Makefile"
