# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	websh
PORTVERSION=	3.6.0b5
PORTREVISION=	3
CATEGORIES=	www tcl
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=tcl/${PORTNAME}/source
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Embeds a TCL8 interpreter in the Apache server

MAKE_JOBS_UNSAFE=	yes

TCL_DVER=	${TCL_VER:S/.//}

USE_TCL=	84+
USE_AUTOTOOLS=	autoconf
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/unix
CONFIGURE_ARGS+=--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tcl=${TCL_LIBDIR}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
SUB_FILES=	httpd.conf pkgIndex.tcl pkg-message
SUB_LIST+=	TCL_DVER=${TCL_DVER} WS_VER=${PORTVERSION}
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} APACHEMODDIR=${APACHEMODDIR}
PLIST_SUB+=	TCL_DVER=${TCL_DVER}

USE_APACHE=	22+
CONFIGURE_ARGS+=--with-httpdinclude=`apxs -q includedir`

CPPFLAGS+=	-I ${LOCALBASE}/include/apr-1
.if !defined(NO_WERROR) && ${CC} == "cc" || ${CC:T:Mgcc*} != ""
CPPFLAGS+=	-Wall -Werror
.endif

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/websh,${PREFIX},' \
		${WRKSRC:H:H}/doc/mod_websh/conf/websh.conf
	for p in ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.html ; do	\
		${SED} -e 's,\.html,.whtml,g' < $$p >	\
			`${DIRNAME} $$p`/`${BASENAME} $$p .html`.whtml;	\
	done
	${REINPLACE_CMD} -e 's,\.html,.whtml,g' ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.ws3
	${REINPLACE_CMD} -e 's|__declspec(dllexport)|DLLEXPORT|' \
		${WRKSRC}/../generic/*.[ch]

post-configure:
	# Remove the "STUBS" and the PACKAGE_* defines, which may conflict
	# with Apache's definitions:
	${REINPLACE_CMD} -e 's,tclstub,tcl,'	\
		-e 's,-DPACKAGE_[^=]*=."[^"]*",,g' ${WRKSRC}/Makefile

post-build test:
	${SETENV} LANG=C ${GMAKE} -C ${WRKSRC} test | ${AWK} '\
		/Failed/ && $$NF {failed=1}	\
		END {exit failed}	\
		{print}'

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/conf/*.ws3	\
		${WRKDIR}/pkgIndex.tcl ${PREFIX}/lib/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/conf/websh.conf	\
		${PREFIX}/etc/websh.conf.dist
	${INSTALL_DATA} ${WRKSRC}/mod_websh${PORTVERSION}.so \
		${PREFIX}/${APACHEMODDIR}/mod_websh.so
	${INSTALL_DATA} ${WRKSRC}/libwebsh${TCL_DVER}.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libwebsh${TCL_DVER}.so.1 \
		${PREFIX}/lib/libwebsh${TCL_DVER}.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/mod_websh/htdocs/*.ws3	\
		${WRKSRC:H:H}/doc/mod_websh/htdocs/*.whtml		\
		${WRKDIR}/httpd.conf ${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC:H:H}/doc/html/* ${DOCSDIR}
.endif

post-install:
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/mod_${MODULENAME}.so"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
