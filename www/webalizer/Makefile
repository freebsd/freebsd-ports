# New ports collection makefile for:	webalizer
# Version required:	1.12
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.2 1998/07/30 13:23:24 andreas Exp $

DISTNAME=	webalizer-1.12-09-src
PKGNAME=	webalizer-1.12
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BIN1=		webalizer
WRKSRC=		${WRKDIR}

.if defined(BATCH)
WEBALIZER_LANG=english
.endif

pre-fetch:
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
	@${ECHO_MSG} "make WEBALIZER_LANG=english"
	@${ECHO_MSG} "make WEBALIZER_LANG=german"
	@${ECHO_MSG} "make WEBALIZER_LANG=french"
	@${ECHO_MSG} "make WEBALIZER_LANG=spanish"
	@${ECHO_MSG} "make WEBALIZER_LANG=dutch"
.endif

post-configure:
.if defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == english
	@${ECHO_MSG} "===> customizing for english"
	${LN} -sf ${WRKSRC}/webalizer_lang.english ${WRKSRC}/webalizer_lang.h
.elif defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == german
	@${ECHO_MSG} "===> customizing for german"
	${LN} -sf ${WRKSRC}/webalizer_lang.german ${WRKSRC}/webalizer_lang.h
.elif defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == french
	@${ECHO_MSG} "===> customizing for french"
	${LN} -sf ${WRKSRC}/webalizer_lang.french ${WRKSRC}/webalizer_lang.h
.elif defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == spanish
	@${ECHO_MSG} "===> customizing for spanish"
	${LN} -sf ${WRKSRC}/webalizer_lang.spanish ${WRKSRC}/webalizer_lang.h
.elif defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == dutch
	@${ECHO_MSG} "===> customizing for dutch"
	${LN} -sf ${WRKSRC}/webalizer_lang.dutch ${WRKSRC}/webalizer_lang.h
.endif

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/webalizer
.for i in CHANGES COPYING Copyright README TODO webalizer.LSM
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/webalizer
.for i in msfree.gif sample.conf
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
