# New ports collection makefile for:	amaya
# Version required:	1.4
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	amaya-src-1.4
PKGNAME=	amaya-1.4
CATEGORIES= 	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://ftp-eu.w3.org/pub/amaya/

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

REQUIRES_MOTIF=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/Thot/obj

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--with-amaya

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${SED} -e 's/CPP.*/CPP = cpp/' <${WRKSRC}/Options.orig\
	 >${WRKSRC}/Options

post-install:
.for file in amaya print
	strip ${PREFIX}/share/thot/applis/bin/${file}
.endfor
.for file in COPYRIGHT.html AmayaPage.html
	${INSTALL_DATA} ${WRKSRC}/../amaya/${file} ${PREFIX}/share/thot/amaya/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/thot/doc/Icons
.for file in Back.gif Browser.gif Editor.gif Forward.gif Image.gif Link.gif\
	 NumList.gif Plugin.gif SaveAs.gif SourceJava.gif Sources.gif\
	 amaya.gif background.gif bug.gif check.gif cross.gif doc48x.gif\
	 drapeau-F.gif eyec.gif find.gif floppy.gif left.gif opera.gif\
	 put.gif question.gif right.gif target.gif ui.gif up.gif warning.gif
	${INSTALL_DATA} ${WRKSRC}/../doc/Icons/${file}\
	 ${PREFIX}/share/thot/doc/Icons/
.endfor
	${MKDIR} ${PREFIX}/share/thot/doc/amaya
.for file in Creating.html MakeBook.html StyleSheets.html Manual.html\
	 Tables.html Math.html Registry.html Transform.html Attributes.html\
	 New.html Views.html Autoconf.html ImageMaps.html Numbering.html\
	 Searching.html BinDist.html Selecting.html Browsing.html CSS.html\
	 Plugins.html Keyboard.html Printing.html Changing.html\
	 Publishing.html Configure.html Links.html Put.html SpellChecking.html
	${INSTALL_DATA} ${WRKSRC}/../doc/amaya/${file}\
	 ${PREFIX}/share/thot/doc/amaya/
.endfor
.endif

.include <bsd.port.mk>
