# New ports collection makefile for:	webalizer
# Version required:	1.22
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.7 1999/06/10 08:15:16 steve Exp $

DISTNAME=	webalizer-1.22-06-src
PKGNAME=	webalizer-1.22.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
BIN1=		webalizer
MAN1=		webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README country-codes.txt webalizer.LSM
SUPP_LANG=	catalan chinese czech dutch english french \
		german italian korean polish portuguese \
		portuguese_brazil romanian russain slowak \
		spanish swedish
WRKSRC=		${WRKDIR}/webalizer-1.22-06

.if defined(BATCH)
WEBALIZER_LANG=english
.endif

.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
.endif

pre-configure:
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
.for i in ${SUPP_LANG}
		@${ECHO_MSG} "make WEBALIZER_LANG=${i}"
.endfor
.endif

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
