# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webalizer
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-2.01-06-src

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dns \
			--with-etcdir=${PREFIX}/etc \
			--with-gdlib=${PREFIX}/lib \
			--with-gd=${PREFIX}/include/gd
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"

MAN1=		webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
SUPP_LANG=	catalan chinese czech danish dutch english estonian \
		finnish french german greek hungarian indonesian \
		italian korean polish portuguese portuguese_brazil \
		romanian russain slowak slovene spanish swedish turkish
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
MAKE_ARGS+=	CFLAGS="${CFLAGS}"

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG=english
.endif

.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
.endif

pre-configure:
	@${PERL5} -pi -e "s=/etc=${PREFIX}/etc=" ${WRKSRC}/webalizer.1
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
	@${ECHO_MSG} "       make WEBALIZER_LANG=<lang>"
	@${ECHO_MSG} "where <lang> is one of:"
	@${ECHO_MSG} ${SUPP_LANG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer ${PREFIX}/bin
	${LN} -sf webalizer ${PREFIX}/bin/webazolver

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
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
