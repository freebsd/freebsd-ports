# New ports collection makefile for:	aspell
# Version required:	0.27.2
# Date created:		7 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $Id: Makefile,v 1.3 1999/02/28 11:49:40 obrien Exp $
#

DISTNAME=	aspell-.27.2
PKGNAME=	aspell-0.27.2
CATEGORIES=	textproc
MASTER_SITES=	http://metalab.unc.edu/kevina/aspell/ \
		ftp://ftp.kddlabs.co.jp/pub/Tools/aspell/ \
		ftp://maroon.webmaster.com/pub/aspell/

MAINTAINER=	josh@quick.net

.include <bsd.port.pre.mk>
.if ${OSREL} < 4
BUILD_DEPENDS=	eg++:${PORTSDIR}/lang/egcs
CC=	egcc
CXX=	eg++
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${WRKSRC}"
USE_GMAKE=	yes
MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}

WORDLIST?=	/usr/share/dict/words

.if !exists(${WORDLIST})
WORDLIST=	${WRKSRC}/english.wl
.endif

post-patch:
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.pre_sed
	@${SED} -e 's%@WORDLIST@%${WORDLIST}%' \
	< ${WRKSRC}/Makefile.in.pre_sed > ${WRKSRC}/Makefile.in
	@${ECHO_MSG} "===>  Using ${WORDLIST} as English word list."

pre-install:
	@${RM} -f ${WRKSRC}/manual/man-html/C_Credits.html \
	          ${WRKSRC}/manual/man-html/D_Glossary.html \
	          ${WRKSRC}/manual/man-html/E_Copyright.html \
	          ${WRKSRC}/manual/man-text/C_Credits.txt \
	          ${WRKSRC}/manual/man-text/D_Glossary.txt \
	          ${WRKSRC}/manual/man-text/E_Copyright.txt

.include <bsd.port.post.mk>
