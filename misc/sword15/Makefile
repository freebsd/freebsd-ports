# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
		http://www.crosswire.org/sword/download/ftpmirror/pub/sword/source/v1.5/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wvengen@stack.nl

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

INCLUDES=	Greek2Greek.h GreekChars.h canon.h cipherfil.h defs.h \
		echomod.h entriesblk.h femain.h filemgr.h gbffootnotes.h \
		gbfheadings.h gbfhtml.h gbfmorph.h gbfplain.h gbfrtf.h \
		gbfstrongs.h gbfthml.h hrefcom.h listkey.h localemgr.h \
		lzsscomprs.h plainfootnotes.h plainhtml.h rawcom.h rawfiles.h \
		rawgbf.h rawld.h rawld4.h rawstr.h rawstr4.h rawtext.h \
		rawverse.h regex.h roman.h rtfhtml.h rwphtml.h rwprtf.h \
		sapphire.h strkey.h swcipher.h swcom.h swcomprs.h swconfig.h \
		swdisp.h swdisprtf.h swdisprtfchap.h swfilter.h swkey.h swld.h \
		swlocale.h swlog.h swmacs.h swmgr.h swmodule.h swobject.h \
		swtext.h swunicod.h swwinlog.h tbdisp.h thmlgbf.h thmlhtml.h \
		thmlolb.h thmlplain.h thmlrtf.h unicodertf.h unixstr.h untgz.h \
		utilconf.h utilfuns.h utilstr.h versekey.h zcom.h zconf.h \
		zipcomprs.h zlib.h ztext.h zverse.h

pre-build:
	@${ECHO} "instdir:=	${PREFIX}" >${WRKSRC}/localport.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libsword.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libsword.so ${PREFIX}/lib/libsword.so.1
	${LN} -sf ${PREFIX}/lib/libsword.so.1 ${PREFIX}/lib/libsword.so
	@${ECHO} "[Install]" >${PREFIX}/etc/sword.conf
	@${ECHO} "DataPath=${DATADIR}" >>${PREFIX}/etc/sword.conf
	${MKDIR} ${DATADIR}
	${MKDIR} ${PREFIX}/include/sword
.for file in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${PREFIX}/include/sword
.endfor

post-install: register
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}

register:
.if !defined(BATCH)
	@${ECHO} "Do you want to help the authors of SWORD to keep track of how many"
	@${ECHO} -n "people use this program and register now ? [y/n] "
	@read answer; \
	 if [ x$$answer = xy -o x$$answer = xY ]; then \
		(cd ${WRKSRC}; ${GMAKE} register;); \
	 fi
.endif

.include <bsd.port.mk>
