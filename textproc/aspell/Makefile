# New ports collection makefile for:	aspell
# Version required:	.24
# Date created:		7 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $Id$
#

DISTNAME=	aspell-.24
PKGNAME=	aspell-0.24
CATEGORIES=	textproc
MASTER_SITES=	http://metalab.unc.edu/kevina/aspell/ \
		ftp://ftp.kddlabs.co.jp/pub/Tools/aspell/ \
		ftp://maroon.webmaster.com/pub/aspell/

MAINTAINER=	josh@quick.net

BUILD_DEPENDS=	${PREFIX}/include/stlport/hash_map:${PORTSDIR}/devel/stlport

WRKSRC=		${WRKDIR}/aspell
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${PREFIX}/include/stlport"
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
	@${RM} -f ${WRKSRC}/man-html/3_aspell.html \
	          ${WRKSRC}/man-html/4_Libray.html \
	          ${WRKSRC}/man-html/manual2.html \
	          ${WRKSRC}/man-text/3_aspell.txt \
	          ${WRKSRC}/man-text/4_Libray.txt \
	          ${WRKSRC}/man-text/manual2.txt

.include <bsd.port.mk>
