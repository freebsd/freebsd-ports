# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xotcl
PORTVERSION=	1.6.7
CATEGORIES?=	lang tcl
MASTER_SITES=	SF \
		http://media.wu-wien.ac.at/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented scripting language based on Tcl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES+=		gmake tcl:84,85

INSTALL_TARGET=	install
ALL_TARGET=	all test-nohttp
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

.if !defined(AOLSERVER_XOTCL)
USE_LDCONFIG=	${PREFIX}/lib/xotcl${PORTVERSION}
GNU_CONFIGURE=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	ACTIWEB TUTORIAL DOCS
OPTIONS_DEFAULT=	ACTIWEB
ACTIWEB_DESC=	Include actiweb
TUTORIAL_DESC=	Install XOTcl tutorial

LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}/include,${LOCALBASE}/lib
.else
AOLSERVERBASE?=	aolserver
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(AOLSERVER_XOTCL)
RUN_DEPENDS+=		${LOCALBASE}/aolserver/bin/init.tcl:${PORTSDIR}/www/aolserver \
			${LOCALBASE}/lib/xotcl${PORTVERSION}/xotclConfig.sh:${PORTSDIR}/lang/xotcl
PLIST=			${WRKDIR}/pkg-plist.aolserver
PLIST_FILES=		${AOLSERVERBASE}/modules/tcl/xotcl.tcl
LATEST_LINK=		aolserver-xotcl
NO_BUILD=		yes
.endif

.if ${PORT_OPTIONS:MACTIWEB}
CONFIGURE_ARGS+=	--with-actiweb --with-gdbm=${LOCALBASE}/include,${LOCALBASE}/lib
LIB_DEPENDS+=		libgdbm.so:${PORTSDIR}/databases/gdbm
PLIST_SUB+=	ACTIWEB=""
.else
PLIST_SUB+=	ACTIWEB="@comment "
.endif

.if ${PORT_OPTIONS:MTUTORIAL}
PLIST_SUB+=	TUTORIAL=""
.else
PLIST_SUB+=	TUTORIAL="@comment "
.endif

INSTALL_TARGET+=	install-shells

.if !defined(AOLSERVER_XOTCL) && !defined(NO_INSTALL_MANPAGES)
MAN1=			xotclsh.1
.endif

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} \
			--libdir=${PREFIX}/lib \
			--enable-threads \
			--with-tcl=${TCL_LIBDIR} \
			--with-tclinclude=${TCL_INCLUDEDIR}/generic/ \
			--with-xotclsh

CONFIGURE_ENV+=		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" \
			PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|TCLSH_PROG=".*"|TCLSH_PROG="${TCLSH}"|g' \
		${WRKSRC}/configure

.if defined(AOLSERVER_XOTCL) # Install for aolserver module

do-install:
	@${INSTALL_DATA} ${WRKSRC}/generic/aol-xotcl.tcl \
		${PREFIX}/${AOLSERVERBASE}/modules/tcl/xotcl.tcl
.endif

.if !defined(AOLSERVER_XOTCL) # Aolserver module has no post-install
post-install:
.if ${PORT_OPTIONS:MTUTORIAL}
	${MKDIR} ${EXAMPLESDIR}/tutorial/html ${EXAMPLESDIR}/tutorial/pdf
.for FILE in langRef-xotcl.pdf tutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${EXAMPLESDIR}/tutorial/pdf
.endfor
	@cd ${WRKSRC}; ${FIND} doc/ -type f \( -name '*.html' -or -name '*.css' -or -name '*.gif' \) \
	-exec ${INSTALL_DATA} ${WRKSRC}/{} ${EXAMPLESDIR}/tutorial/html \;
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog README README.aol
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/xotclsh.1 ${PREFIX}/man/man1/
.endif
.endif
.include <bsd.port.mk>
