# New ports collection makefile for:	webalizer
# Version required:	1.22
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.5 1999/01/26 02:18:07 steve Exp $

DISTNAME=	webalizer-1.22-03-src
PKGNAME=	webalizer-1.22.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BIN1=		webalizer
MAN1=		webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README country-codes.txt webalizer.LSM
SUPP_LANG=	english german french spanish dutch italian polish \
		catalan czech portuguese_brazil russian slovak swedish \
		portugues
WRKSRC=		${WRKDIR}/webalizer-1.22-03

.if defined(BATCH)
WEBALIZER_LANG=english
.endif
WEBALIZER_LANG=english

pre-fetch:
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
.for i in ${SUPP_LANG}
		@${ECHO_MSG} "make WEBALIZER_LANG=${i}"
.endfor
.endif

post-configure:
.for i in ${SUPP_LANG}
.if defined(WEBALIZER_LANG) && ${WEBALIZER_LANG} == ${i}
		@${ECHO_MSG} "===> customizing for ${i}"
		@cd ${WRKSRC}; \
		${LN} -sf lang/webalizer_lang.${i} webalizer_lang.h
.endif
.endfor

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin/${i}
.endfor

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/webalizer
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/webalizer
.for i in msfree.gif sample.conf webalizer.gif
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
