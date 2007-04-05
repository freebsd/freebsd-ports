# New ports collection makefile for:	xotcl
# Date created:				Mon Sep 25 15:31:00 CET 2006
# Whom:					Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	xotcl
PORTVERSION=	1.5.3
PORTREVISION=	4
CATEGORIES?=	lang tcl84
MASTER_SITES=	http://media.wu-wien.ac.at/download/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Object-oriented scripting language based on Tcl

USE_TCL=		84+
USE_TCL_THREADS=	yes

INSTALL_TARGET=	install
ALL_TARGET=	all test-nohttp
USE_GMAKE=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(AOLSERVER_XOTCL)
USE_LDCONFIG=	${PREFIX}/xotcl${PORTVERSION}
GNU_CONFIGURE=	yes

OPTIONS=	ACTIWEB		"Include actiweb"		on \
		TUTORIAL	"Install XOTcl tutorial" 	off
.else
AOLSERVERBASE?=	${LOCALBASE}/aolserver
.endif

.include <bsd.port.pre.mk>

.if defined(AOLSERVER_XOTCL)
RUN_DEPENDS+=		${LOCALBASE}/aolserver/bin/init.tcl:${PORTSDIR}/www/aolserver \
			${LOCALBASE}/lib/xotcl${PORTVERSION}/xotclConfig.sh:${PORTSDIR}/lang/xotcl
PLIST=			${WRKDIR}/pkg-plist.aolserver
PLIST_FILES=		${AOLSERVERBASE:S/${LOCALBASE}\///}/modules/tcl/xotcl.tcl
LATEST_LINK=		aolserver-xotcl
NO_BUILD=		yes
.endif

.if defined(WITH_ACTIWEB)
CONFIGURE_ARGS+=	--with-actiweb --with-gdbm=${LOCALBASE}/include,${LOCALBASE}/lib
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=	ACTIWEB=""
.else
PLIST_SUB+=	ACTIWEB="@comment "
.endif

.if defined(WITH_TUTORIAL)
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

post-patch:
	@${REINPLACE_CMD} -e 's|TCLSH_PROG=".*"|TCLSH_PROG="${TCLSH}"|g' \
		${WRKSRC}/configure

.if defined(AOLSERVER_XOTCL) # Install for aolserver module

do-install:
	@${INSTALL_DATA} ${WRKSRC}/generic/aol-xotcl.tcl ${AOLSERVERBASE}/modules/tcl/xotcl.tcl
.endif

.if !defined(AOLSERVER_XOTCL) # Aolserver module has no post-install
post-install:
.if defined(WITH_TUTORIAL)
	${MKDIR} ${EXAMPLESDIR}/tutorial/html ${EXAMPLESDIR}/tutorial/pdf
.for FILE in langRef-xotcl.pdf tutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${EXAMPLESDIR}/tutorial/pdf
.endfor
	@cd ${WRKSRC}; ${FIND} doc/ -type f \( -name '*.html' -or -name '*.css' -or -name '*.gif' \) \
	-exec ${INSTALL_DATA} ${WRKSRC}/{} ${EXAMPLESDIR}/tutorial/html \;
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/announces
.for FILE in COPYRIGHT ChangeLog README README.aol doc/TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}; ${FIND} doc/ -name 'Announce-*' -type f \
	-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DOCSDIR}/announces \;
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/xotclsh.1 ${PREFIX}/man/man1/
.endif
.endif
.include <bsd.port.post.mk>
