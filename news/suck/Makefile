# Created by: Noritaka Ishizumi <graphite@taurus.bekkoame.or.jp>
# $FreeBSD$

PORTNAME=	suck
PORTVERSION=	4.3.2
PORTREVISION=	2
CATEGORIES=	news
#MASTER_SITES=	http://www.sucknews.org/
MASTER_SITES=	http://home.comcast.net/~bobyetman/ \
		LOCAL/dinoex
PKGNAMESUFFIX?=	${CNEWS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receives/sends news to/from localhost via NNTP

CONFLICTS?=	suckblow-1.*

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ENV=	CHKHISTORY=chkhistory_db.o

MAN1=		suck.1 rpost.1 testhost.1 lmove.1
EX_SCRIPTS=	get.news.generic get.news.inn perl_kill.pl perl_xover.pl \
		post_filter.pl put.news put.news.pl put.news.sm put.news.sm.pl
EX_DATA=	suckkillfile.sample sucknewsrc.sample suckothermsgs.sample

OPTIONS_DEFINE=	SSL EXAMPLES

.include <bsd.port.options.mk>

.if defined(NEWSBIN) && !defined(SUCK_WITH_INN)
CNEWS_PORT?=	news/cnews
CNEWS_SUFFIX=	-cnews
MAKE_ENV+=	DB_TYPE=-DUSE_DBZ DB_LIB=-lcnews
MAKE_ENV+=	DB_LIB_LOC=-L${LOCALBASE}/lib
MAKE_ENV+=	INCDIR2=-I${LOCALBASE}/include
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/${CNEWS_PORT}
CONFLICTS+=	suck-4.*
.else
CFLAGS+=	-DNO_CONFIGDATA -I${LOCALBASE}/include/inn
MAKE_ENV+=	DB_TYPE="-DUSE_INN23 -DDO_TAGGED_HASH"
MAKE_ENV+=	DB_LIB="-linn -lstorage"
MAKE_ENV+=	DB_LIB_LOC=-L${LOCALBASE}/news/lib
MAKE_ENV+=	DB_INC_LOC="-I${LOCALBASE}/news/include -I${LOCALBASE}/news/include/inn"
MAKE_ENV+=	INCDIR2=-I${LOCALBASE}/include
BUILD_DEPENDS+=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
CONFLICTS+=	suck-cnews-4.*
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
MAKE_ENV+=	SSL_LIB="-lssl -lcrypto"
MAKE_ENV+=	SSL_DEFS="-I${OPENSSLINC} -DHAVE_LIBSSL"
MAKE_ENV+=	SSL_LIB_LOC="-L${OPENSSLLIB}"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s=/usr/local/=${LOCALBASE}/=" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s=/usr/local/lib/suck=${PREFIX}/lib/suck=" \
		${WRKSRC}/suck_config.h
.if defined(NEWSBIN) && !defined(SUCK_WITH_INN)
	@${REINPLACE_CMD} -e -e "s=/usr/local/news/lib=${NEWSCTL}=" \
		${WRKSRC}/suck_config.h
.else
	@${REINPLACE_CMD} -e "s=/usr/local/news/lib=${LOCALBASE}/news/lib=" \
		${WRKSRC}/suck_config.h
.endif
# Add missing dependency to allow parallel (-jX) builds
	@${GREP} -l '#include "phrases.h"' ${WRKSRC}/*.c | ${SED} -e \
		's=.*/== ; s=\.c=.o= ; $$s=$$=: phrases.h=' | ${XARGS} \
		>> ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${EX_SCRIPTS:S=^=${WRKSRC}/sample/=} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EX_DATA:S=^=${WRKSRC}/sample/=} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
