PORTNAME=	websh
DISTVERSION=	3.6.0b5
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	www tcl
MASTER_SITES=	https://archive.apache.org/dist/tcl/${PORTNAME}/source/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Embeds a TCL8 interpreter in the Apache server
WWW=		https://tcl.apache.org/websh/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC:H:H}/LICENSE

USES=		apache autoreconf gmake tcl:tea
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-httpdinclude=`apxs -q includedir`

MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I ${LOCALBASE}/include/apr-1
.if !defined(NO_WERROR) && ${CC} == "cc" || ${CC:T:Mgcc*} != ""
CPPFLAGS+=	-Wall -Werror
.endif

SUB_FILES=	httpd.conf pkgIndex.tcl pkg-message
SUB_LIST+=	LIBSUF=${LIBSUF} WS_VER=${DISTVERSION}
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} APACHEMODDIR=${APACHEMODDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/unix

PLIST_SUB+=	LIBSUF=${LIBSUF}
PLIST_SUB+=	NOMINORVERSION=${TCL_VER:C/8.[345]//:C/^..*/"@comment "/}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

LIBSUF=		${DISTVERSION:S/.//g}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/websh,${PREFIX},' \
		${WRKSRC:H:H}/doc/mod_websh/conf/websh.conf
	for p in ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.html ; do	\
		${SED} -e 's,\.html,.whtml,g' < $$p >	\
			`${DIRNAME} $$p`/`${BASENAME} $$p .html`.whtml;	\
	done
	${REINPLACE_CMD} -e 's,\.html,.whtml,g' ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.ws3
	${REINPLACE_CMD} -e 's|__declspec(dllexport)|DLLEXPORT|' \
		${WRKSRC:H}/generic/*.[ch]

post-configure:
	# Remove the "STUBS" and the PACKAGE_* defines, which may conflict
	# with Apache's definitions:
	${REINPLACE_CMD} -e 's,tclstub,tcl,'	\
		-e 's,-DPACKAGE_[^=]*=."[^"]*",,g' ${WRKSRC}/Makefile

test:
	${SETENV} HOME=${WRKDIR} ${MAKE_CMD} -C ${WRKSRC} test | ${AWK} '\
		/Failed/ && $$NF {failed=1}	\
		END {exit failed}	\
		{print}'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/conf/*.ws3	\
		${WRKDIR}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/conf/websh.conf	\
		${STAGEDIR}${PREFIX}/etc/websh.conf.dist
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_LIB} ${WRKSRC}/mod_websh${DISTVERSION}.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_websh.so
	if [ -f ${WRKSRC}/libwebsh${LIBSUF}.so.1.0 ]; then	\
		${INSTALL_LIB} ${WRKSRC}/libwebsh${LIBSUF}.so.1.0 \
			${STAGEDIR}${PREFIX}/lib;	\
		${LN} -sf libwebsh${LIBSUF}.so.1.0	\
			${STAGEDIR}${PREFIX}/lib/libwebsh${LIBSUF}.so.1;	\
		${LN} -sf libwebsh${LIBSUF}.so.1.0	\
			${STAGEDIR}${PREFIX}/lib/libwebsh${LIBSUF}.so;	\
	else	\
		${INSTALL_LIB} ${WRKSRC}/libwebsh${LIBSUF}.so.1 \
			${STAGEDIR}${PREFIX}/lib;	\
		${LN} -sf libwebsh${LIBSUF}.so.1	\
			${STAGEDIR}${PREFIX}/lib/libwebsh${LIBSUF}.so;	\
	fi
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.ws3	\
		${WRKSRC:H:H}/doc/mod_websh/htdocs/*.whtml		\
		${WRKDIR}/httpd.conf ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
