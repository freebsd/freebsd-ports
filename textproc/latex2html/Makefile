# New ports collection makefile for:	 latex2html
# Version required:	98.1
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.4 1998/09/15 21:31:53 asami Exp $
#

DISTNAME=	latex2html-98.1p1
CATEGORIES=	textproc
MASTER_SITES=	http://www-dsed.llnl.gov/files/programs/unix/latex2html/sources/ \
		ftp://ftp.mpn.com/pub/nikos/latex2html-mirror/sources/

MAINTAINER=	brett@peloton.physics.montana.edu

RUN_DEPENDS=	${PREFIX}/bin/latex:${PORTSDIR}/print/latex \
		${PREFIX}/bin/dvips:${PORTSDIR}/print/dvips \
		${PREFIX}/bin/gs:${PORTSDIR}/print/ghostscript5 \
		${X11BASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm

WRKSRC=	${WRKDIR}/latex2html

USE_PERL5=	yes
NO_BUILD=	yes
IS_INTERACTIVE=	yes
NO_PACKAGE=	An interrogation follows installation

do-install:
	@${MKDIR} ${PREFIX}/share/latex2html
	@${INSTALL_DATA} ${FILESDIR}/local.pm ${PREFIX}/share/latex2html
	@ for dir in makeseg IndicTeX-HTML cweb2html docs example icons.gif icons.png styles tests versions; do \
		${CP} -R ${WRKSRC}/$$dir ${PREFIX}/share/latex2html; \
	done
	@ for prog in Override.pm configure-pstoimg install-test latex2html makemap pstoimg\
		pstoimg_nopipes texexpand; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$prog ${PREFIX}/share/latex2html; \
	done
	@ for file in FAQ MANIFEST README README.dvips dot.latex2html-init latex2html.config ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/latex2html; \
	done
	@${MKDIR} ${PREFIX}/share/texmf/tex/latex/latex2html
	@${INSTALL_DATA} ${WRKSRC}/texinputs/* ${PREFIX}/share/texmf/tex/latex/latex2html

post-install:
	@cd ${PREFIX}/share/latex2html && env LATEX2HTMLDIR=${PREFIX}/share/latex2html ${PERL5} ${PREFIX}/share/latex2html/install-test
	@${INSTALL_SCRIPT} ${PREFIX}/share/latex2html/latex2html ${PREFIX}/bin
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "Latex2html has now been installed with a very basic"
	@${ECHO_MSG} "configuration and HTML specific style files have been"
	@${ECHO_MSG} "moved to ${PREFIX}/share/texmf/tex/latex/latex2html."
	@${ECHO_MSG} "You will need to make sure that latex can now see these"
	@${ECHO_MSG} "style files, for instance by running texhash if you are"
	@${ECHO_MSG} "using teTeX.  Due to the differences in how web "
	@${ECHO_MSG} "servers are set up, it's probably a good idea to read"
	@${ECHO_MSG} "through the configuration, which can be found in "
	@${ECHO_MSG} "${PREFIX}/local/share/latex2html/latex2html.config"
	@${ECHO_MSG} "and adjusting things to set up system wide preferences."
	@${ECHO_MSG} "You may then want to re-run install-test found in the"
	@${ECHO_MSG} "same directory and copy the new latex2html script"
	@${ECHO_MSG} "to ${PREFIX}/local/bin.  Individual user configurations"
	@${ECHO_MSG} "can be accomplished by placing a copy of"
	@${ECHO_MSG} "${PREFIX}/local/share/latex2html/dot.latex2html-init"
	@${ECHO_MSG} "in the user's home directory and editing to preference."
	@${ECHO_MSG} "********************************************************"

.include <bsd.port.mk>
