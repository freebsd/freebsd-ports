# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webalizer
PORTVERSION=	2.1.9
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-2.01-09-src

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(LIB_DEPENDS)
LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG?=english
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-dns \
			--with-etcdir=${PREFIX}/etc \
			--with-gdlib=${PREFIX}/lib \
			--with-gd=${PREFIX}/include/gd
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
CFLAGS+=	-DLINKLIST_MAX_STRING=256
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
MAN1=		${PKGNAMEPREFIX}webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
PLIST_SUB+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}
SUPP_LANG=	catalan chinese croatian czech danish dutch english \
		estonian finnish french galician german greek hungarian \
		icelandic indonesian italian japanese korean latvian \
		malay norwegian polish portuguese portuguese_brazil \
		romanian romanian-iso-8859-2 russain serbian \
		simplified_chinese slowak slovene spanish swedish \
		turkish ukrainian

.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
.endif

pre-configure:
	@${PERL5} -pi -e "s=/etc=${PREFIX}/etc=" ${WRKSRC}/webalizer.1
	@${PERL5} -pi -e "s=webalizer.conf=${PKGNAMEPREFIX}webalizer.conf=" \
		${WRKSRC}/webalizer.c
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
	@${ECHO_MSG} "       make WEBALIZER_LANG=<lang>"
	@${ECHO_MSG} "where <lang> is one of:"
	@${ECHO_MSG} ${SUPP_LANG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webazolver
	${INSTALL_DATA} ${WRKSRC}/sample.conf \
		${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ;

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>
