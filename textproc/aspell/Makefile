# New ports collection makefile for:	aspell
# Version required:	0.28.2.1
# Date created:		7 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	aspell-.28.2.1
PKGNAME=	aspell-0.28.2.1
CATEGORIES=	textproc
MASTER_SITES=	http://metalab.unc.edu/kevina/aspell/ \
		ftp://ftp.kddlabs.co.jp/pub/Tools/aspell/ \
		ftp://maroon.webmaster.com/pub/aspell/

MAINTAINER=	ade@lovett.com

# As and when gcc-2.95.1 becomes the 4.x system compiler, we can
# remove this and uncomment USE_NEWGCC
BUILD_DEPENDS=	g++295:${PORTSDIR}/lang/egcs

CC=		gcc295
CXX=		g++295
#USE_NEWGCC=	yes
USE_LIBTOOL=	yes
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

.include <bsd.port.mk>
