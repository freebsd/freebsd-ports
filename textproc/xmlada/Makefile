# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlada
PORTVERSION=	4.6.0.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	xmlada-gpl-2015-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore XML suite for the Ada language

LICENSE=	GPLv3

USES=		ada
MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		LIBVER=${PORTVERSION}
ALL_TARGET=	schema/lib/static/libxmlada_schema.a \
		schema/lib/relocatable/libxmlada_schema.so
PLIST_SUB+=	LIBVER=${PORTVERSION}
MAKEFILE=	Makefile.bsd
PORTDOCS=	*
DUNICODE=	${WRKSRC}/unicode/dummy_unicode.adb
DINPSRC=	${WRKSRC}/input_sources/dummy_input_sources.adb
DSAX=		${WRKSRC}/sax/dummy_sax.adb
DDOM=		${WRKSRC}/dom/dummy_dom.adb
DSCHEMA=	${WRKSRC}/schema/dummy_schema.adb

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
ALL_TARGET+=	docs
.endif

FIND1=	cd ${WRKSRC}/unicode && ${FIND} -s * \( -name "unicode*.ad[bs]" \
	-a ! -name "unicode.ads" \) -exec ${PRINTF} ', "%s"' {} \;
FIND2=	cd ${WRKSRC}/input_sources && ${FIND} -s * \( -name "input*.ad[bs]" \
	-a ! -name "input_sources.ads" \) -exec ${PRINTF} ', "%s"' {} \;
FIND3=	cd ${WRKSRC}/sax && \
	${FIND} -s * -name "sax-*.ad[bs]" -exec ${PRINTF} ', "%s"' {} \;
FIND4=	cd ${WRKSRC}/dom && \
	${FIND} -s * -name "dom-*.ad[bs]" -exec ${PRINTF} ', "%s"' {} \;
FIND5=	cd ${WRKSRC}/schema && ${FIND} -s * \( -name "schema*.ad[bs]" \
	-a ! -name "schema.ads" \) -depth 0 -maxdepth 0 \
	-exec ${PRINTF} ', "%s"' {} \;

post-patch: dummy-unicode dummy-input_sources dummy-sax dummy-dom dummy-schema
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}
	# vital gpr files are missing from GPL 2015, recreate them
	@${SED} -e 's|@exec_prefix@|$${prefix}|' \
		-e 's|@libdir@|$${exec_prefix}/lib|' \
		-e 's|@includedir@|$${prefix}/include|' \
		-e 's|@DEFAULT_LIBRARY_TYPE@|static|' \
		-e 's|@PACKAGE_VERSION@|${PORTVERSION}|' \
		${WRKSRC}/xmlada-config.in > ${WRKSRC}/xmlada-config
	@${SED} -e '/^with/d' -e 's|@ZONE@|unicode|' \
		-e "s|@FILES@|`${FIND1}`|" \
		-e 's|@VERSION@|${PORTVERSION}|' ${FILESDIR}/generic_gpr.in \
		> ${WRKSRC}/distrib/xmlada_unicode.gpr
	@${SED} -e 's|@DEPENDS@|unicode|' -e 's|@ZONE@|input_sources|' \
		-e "s|@FILES@|`${FIND2}`|" \
		-e 's|@VERSION@|${PORTVERSION}|' ${FILESDIR}/generic_gpr.in \
		> ${WRKSRC}/distrib/xmlada_input_sources.gpr
	@${SED} -e 's|@DEPENDS@|input_sources|' -e 's|@ZONE@|sax|' \
		-e "s|@FILES@|`${FIND3}`|" \
		-e 's|@VERSION@|${PORTVERSION}|' ${FILESDIR}/generic_gpr.in \
		> ${WRKSRC}/distrib/xmlada_sax.gpr
	@${SED} -e 's|@DEPENDS@|sax|' -e 's|@ZONE@|dom|' \
		-e "s|@FILES@|`${FIND4}`|" \
		-e 's|@VERSION@|${PORTVERSION}|' ${FILESDIR}/generic_gpr.in \
		> ${WRKSRC}/distrib/xmlada_dom.gpr
	@${SED} -e 's|@DEPENDS@|dom|' -e 's|@ZONE@|schema|' \
		-e "s|@FILES@|`${FIND5}`|" \
		-e 's|@VERSION@|${PORTVERSION}|' ${FILESDIR}/generic_gpr.in \
		> ${WRKSRC}/distrib/xmlada_schema.gpr
	# Since we want to pull in all 5 libs, we only need to specify schema
	${REINPLACE_CMD} -e '/unicode/d' ${WRKSRC}/distrib/xmlada.gpr

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/xmlada \
		${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/xmlada/relocatable \
		${STAGEDIR}${PREFIX}/lib/xmlada/static \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dom/*.ad[bs] \
		${WRKSRC}/input_sources/*.ad[bs] \
		${WRKSRC}/sax/*.ad[bs] \
		${WRKSRC}/schema/*.ad[bs] \
		${WRKSRC}/unicode/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/xmlada
	${RM} ${STAGEDIR}${PREFIX}/include/xmlada/dummy_*.adb
	${INSTALL_DATA} ${WRKSRC}/dom/obj/relocatable/*.ali \
		${WRKSRC}/input_sources/obj/relocatable/*.ali \
		${WRKSRC}/sax/obj/relocatable/*.ali \
		${WRKSRC}/schema/obj/relocatable/*.ali \
		${WRKSRC}/unicode/obj/relocatable/*.ali \
		${WRKSRC}/dom/lib/relocatable/* \
		${WRKSRC}/input_sources/lib/relocatable/* \
		${WRKSRC}/sax/lib/relocatable/* \
		${WRKSRC}/schema/lib/relocatable/* \
		${WRKSRC}/unicode/lib/relocatable/* \
		${STAGEDIR}${PREFIX}/lib/xmlada/relocatable
	${INSTALL_DATA} ${WRKSRC}/dom/obj/static/*.ali \
		${WRKSRC}/input_sources/obj/static/*.ali \
		${WRKSRC}/sax/obj/static/*.ali \
		${WRKSRC}/schema/obj/static/*.ali \
		${WRKSRC}/unicode/obj/static/*.ali \
		${WRKSRC}/dom/lib/static/* \
		${WRKSRC}/input_sources/lib/static/* \
		${WRKSRC}/sax/lib/static/* \
		${WRKSRC}/schema/lib/static/* \
		${WRKSRC}/unicode/lib/static/* \
		${STAGEDIR}${PREFIX}/lib/xmlada/static
	${INSTALL_DATA} ${WRKSRC}/distrib/xml*.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/distrib/xmlada_gps.py \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${INSTALL_SCRIPT} ${WRKSRC}/xmlada-config ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/docs/_build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${RM} -r ${STAGEDIR}${DOCSDIR}/_sources \
		${STAGEDIR}${DOCSDIR}/.buildinfo
.endif

dummy-unicode:
	@${GREP} ^package ${WRKSRC}/unicode/unicode-*.ads | \
		${AWK} '{print "with " $$2 ";"}' | ${SORT} > ${DUNICODE}
	@${ECHO} 'procedure dummy_unicode is' >> ${DUNICODE}
	@${ECHO} 'begin' >> ${DUNICODE}
	@${ECHO} '   null;' >> ${DUNICODE}
	@${ECHO} 'end dummy_unicode;' >> ${DUNICODE}

dummy-input_sources:
	@${GREP} ^package ${WRKSRC}/input_sources/input_sources-*.ads | \
		${AWK} '{print "with " $$2 ";"}' | ${SORT} > ${DINPSRC}
	@${ECHO} 'procedure dummy_input_sources is' >> ${DINPSRC}
	@${ECHO} 'begin' >> ${DINPSRC}
	@${ECHO} '   null;' >> ${DINPSRC}
	@${ECHO} 'end dummy_input_sources;' >> ${DINPSRC}

dummy-sax:
	@${GREP} ^package ${WRKSRC}/sax/sax-*.ads | \
		${AWK} '{print "with " $$2 ";"}' | ${SORT} > ${DSAX}
	@${ECHO} 'procedure dummy_sax is' >> ${DSAX}
	@${ECHO} 'begin' >> ${DSAX}
	@${ECHO} '   null;' >> ${DSAX}
	@${ECHO} 'end dummy_sax;' >> ${DSAX}

dummy-dom:
	@${GREP} ^package ${WRKSRC}/dom/dom-*.ads | \
		${AWK} '{print "with " $$2 ";"}' | ${SORT} > ${DDOM}
	@${ECHO} 'procedure dummy_dom is' >> ${DDOM}
	@${ECHO} 'begin' >> ${DDOM}
	@${ECHO} '   null;' >> ${DDOM}
	@${ECHO} 'end dummy_dom;' >> ${DDOM}

dummy-schema:
	@${GREP} ^package ${WRKSRC}/schema/schema-*.ads | \
		${AWK} '{print "with " $$2 ";"}' | ${SORT} > ${DSCHEMA}
	@${ECHO} 'procedure dummy_schema is' >> ${DSCHEMA}
	@${ECHO} 'begin' >> ${DSCHEMA}
	@${ECHO} '   null;' >> ${DSCHEMA}
	@${ECHO} 'end dummy_schema;' >> ${DSCHEMA}

.include <bsd.port.mk>
