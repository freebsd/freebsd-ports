# New ports collection makefile for:	xotcl
# Date created:				Mon Sep 25 15:31:00 CET 2006
# Whom:					Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	xotcl
PORTVERSION=	1.5.2
CATEGORIES=	lang tcl83 tcl84
MASTER_SITES=	http://media.wu-wien.ac.at/download/

MAINTAINER=	martin@matuska.org
COMMENT=	Object-oriented scripting language based on Tcl

GNU_CONFIGURE=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes
ALL_TARGET=	all test-nohttp
INSTALL_TARGET=	install-binaries install-libraries
USE_LDCONFIG=	yes
USE_GMAKE=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS=	AOLSERVER	"AOL server module"		off \
		TUTORIAL	"Install XOTcl tutorial" 	off

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} \
			--libdir=${PREFIX}/lib \
			--with-tcl=${TCL_LIBDIR} \
			--with-tclinclude=${TCL_INCLUDEDIR}/generic/ \
			--with-xotclsh

.include <bsd.port.pre.mk>

.if defined(WITH_AOLSERVER)
BUILD_DEPENDS+=		${LOCALBASE}/aolserver/bin/init.tcl:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=		${BUILD_DEPENDS}
PLIST_SUB+=		AOLSERVER=""
INSTALL_TARGET=		install-aol
.else
PLIST_SUB+=		AOLSERVER="@comment "
.endif

.if defined(WITH_TUTORIAL)
PLIST_SUB+=	TUTORIAL=""
.else
PLIST_SUB+=	TUTORIAL="@comment "
.endif

INSTALL_TARGET+=	install-shells
.if !defined(NO_INSTALL_MANPAGES)
MAN1=			xotclsh.1
.endif

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
.include <bsd.port.post.mk>
