# New ports collection makefile for:   w3m
# Date Created:			7 Oct 1999
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	w3m
PORTVERSION=	0.2.1
CATEGORIES+=	www ipv6
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/w3m/ \
		http://mi.med.tohoku.ac.jp/~satodai/w3m/src/ \
		ftp://ftp.firedrake.org/w3m/ \
		ftp://ftp.umlauf.de/pub/w3m/ \
		http://www.instinct.org/w3m/ \
		http://grilli.net/mirrors/w3m/download/

MAINTAINER?=	nobutaka@nobutaka.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libgc.a:${PORTSDIR}/devel/boehm-gc

MAN1=		w3m.1
MANLANG=	""
CFLAGS+=	-pipe

CONFIG_H=	${WRKSRC}/config.h
DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu
SED_CMD=	-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
SED_CMD+=	-e "s,undef INET6,define INET6,g"
.endif

.if defined(JAPANESE)
SED_CMD+=	-e "s,undef JAPANESE,define JAPANESE,g"
MANLANG+=	ja
DOCS_JP=	${DOCS} HISTORY.kokb README.SSL README.cookie \
		README.keymap README.mailcap README.menu
.endif

.if defined(USE_OPENSSL)
SSL_CFLAGS=	-I${OPENSSLINC}/openssl -I${OPENSSLINC} ${OPENSSL_CFLAGS}
SSL_LIBS=	-L${OPENSSLLIB} -lssl -lcrypto

SED_CMD+=	-e "s,undef USE_SSL,define USE_SSL,g" \
		-e "s,undef USE_SSL_VERIFY, define USE_SSL_VERIFY,g"
MAKE_FLAGS+=	DEFS="${SSL_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${SSL_LIBS} ${EXTRA_SSL_LIBS} -L${LOCALBASE}/lib"
.else
MAKE_FLAGS+=	DEFS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
.endif

post-configure:
	@${CP} ${CONFIG_H} ${CONFIG_H}.in
	@${SED} ${SED_CMD} < ${CONFIG_H}.in > ${CONFIG_H}
	@${SED} -e "s,@PERL@,${PERL},g" \
		-e "s,@CYGWIN@,0,g" \
		< ${WRKSRC}/scripts/dirlist.in > ${WRKSRC}/scripts/dirlist.cgi

post-install:
.if !defined(NOPORTDOCS)
.if defined(JAPANESE)
	@${MKDIR} ${PREFIX}/share/doc/ja/w3m
	@cd ${WRKSRC}/doc-jp; \
	for i in ${DOCS_JP} ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/ja/w3m/ ; \
	done
.endif
	@cd ${WRKSRC}/doc; \
	for i in ${DOCS} ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/w3m/ ; \
	done
.endif
	@${INSTALL_MAN} ${WRKSRC}/doc/w3m.1 ${PREFIX}/man/man1
.if defined(JAPANESE)
	@${INSTALL_MAN} ${WRKSRC}/doc-jp/w3m.1 ${PREFIX}/man/ja/man1
.endif

.include <bsd.port.post.mk>
