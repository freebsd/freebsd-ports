# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.1a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
		http://www.crosswire.org/sword/download/ftpmirror/pub/sword/source/v1.5/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wvengen@stack.nl

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

INCLUDES=	Greek2Greek.h GreekChars.h canon.h cipherfil.h defs.h \
		echomod.h femain.h filemgr.h gbffootnotes.h gbfhtml.h \
		gbfplain.h gbfrtf.h gbfstrongs.h gbfthml.h hrefcom.h \
		listkey.h localemgr.h lzsscomprs.h plainfootnotes.h \
		plainhtml.h rawcom.h rawfiles.h rawgbf.h rawld.h rawstr.h \
		rawtext.h rawverse.h regex.h rtfhtml.h rwphtml.h rwprtf.h \
		sapphire.h strkey.h swcipher.h swcom.h swcomprs.h \
		swconfig.h swdisp.h swdisprtf.h swdisprtfchap.h swfilter.h \
		swkey.h swld.h swlocale.h swlog.h swmacs.h swmgr.h \
		swmodule.h swtext.h swwinlog.h tbdisp.h thmlgbf.h \
		thmlhtml.h thmlplain.h thmlrtf.h unixstr.h utilconf.h \
		utilfuns.h utilstr.h versekey.h zcom.h zipcomprs.h ztext.h \
		zverse.h

pre-build:
	@${ECHO} "instdir:=	${PREFIX}" >${WRKSRC}/localport.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libsword.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libsword.so ${PREFIX}/lib/libsword.so.1
	${LN} -s ${PREFIX}/lib/libsword.so.1 ${PREFIX}/lib/libsword.so
	${INSTALL_DATA} ${FILESDIR}/sword.conf ${PREFIX}/etc
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
