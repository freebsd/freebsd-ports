# New ports collection makefile for:	webalizer
# Version required:	1.20
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.4 1998/08/17 00:34:42 steve Exp $

DISTNAME=	webalizer-1.20-07-src
PKGNAME=	webalizer-1.20
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
SUPP_LANG=	english german french spanish dutch italian polish
WRKSRC=		${WRKDIR}

.if defined(BATCH)
WEBALIZER_LANG=english
.endif

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
		${LN} -sf ${WRKSRC}/webalizer_lang.${i} \
			  ${WRKSRC}/webalizer_lang.h
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
.for i in msfree.gif sample.conf
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
