# New ports collection makefile for:	siag (Scheme In A Grid)
# Version required:	2.65
# Date created:		27 Jan 1998
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.1.1.1 1998/02/28 03:38:32 itojun Exp $
#

DISTNAME=	siag-2.65
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=	itojun@itojun.org

BROKEN=		fetch
USE_X11=	yes
WRKSRC=		${WRKDIR}/siag
CONF=	siag/data.scm siag/find.scm siag/keytable.scm siag/menu.scm \
	siag/plot.scm siag/siag.scm siag/splot.scm siag/startup.siag \
	siod/siod.scm xcommon/StringDefs.scm xcommon/form.scm
DOC1=	BUGS CHANGES COPYING Copying README TODO c-expr.html commands.html \
	concepts.html fileformats.html form.html gnuplot.html howto.html \
	intro.html invocation.html kalkyl.gif keys.html mouse.html scheme.html \
	scrollbars.html siag.gif siag.html strings.html toolbar.html
EXAMPLES=	fibonacci-c.siag fibonacci.siag filemgr.scm fonts.siag \
		formtest.siag group.siag heaven-c.siag heaven-guile.siag \
		heaven-tcl.siag heaven.siag heaven.xbm hyperhelp.siag \
		image.siag kalkyl.siag mailaddr.csv mailto.scm \
		multtabl-c.siag multtabl.siag passwd.siag plot.siag \
		property.siag siag-http.scm siag-net.scm sincos.siag \
		strfib.siag strings.siag surface1.siag surface2.siag \
		tcltest.siag usermgr.scm
DOC2=	COPYING.LIB credits.html embedding.html form.html interpreters.html \
	office.html search.html siaghelp.html

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} sh INSTALL)

do-install:
	(cd ${WRKSRC}/xsiag; ${SETENV} ${MAKE_ENV} ${MAKE} install)
	(cd ${WRKSRC}/tsiag; ${SETENV} ${MAKE_ENV} ${MAKE} install)
	dst=${PREFIX}/lib/siag; \
	${MKDIR} $$dst/siag; \
	${MKDIR} $$dst/siod; \
	${MKDIR} $$dst/xcommon; \
	for i in ${CONF}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i $$dst/$$i; \
	done
.if !defined(NOPORTDOCS)
	dst=${PREFIX}/lib/siag/siag/docs; ${MKDIR} $$dst; \
	for i in ${DOC1}; do \
		${INSTALL_DATA} ${WRKSRC}/siag/docs/$$i $$dst; \
	done
	dst=${PREFIX}/lib/siag/siag/examples; ${MKDIR} $$dst; \
	for i in ${EXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/siag/examples/$$i $$dst; \
	done
	dst=${PREFIX}/lib/siag/common/docs; ${MKDIR} $$dst; \
	for i in ${DOC2}; do \
		${INSTALL_DATA} ${WRKSRC}/common/docs/$$i $$dst; \
	done
.endif
	@${SED} -e 's#/usr/X11R6#${PREFIX}#' ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
