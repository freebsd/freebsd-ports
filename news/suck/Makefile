# New ports collection makefile for:	suck
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $FreeBSD$
#

PORTNAME=	suck
PORTVERSION=	4.3.2
PORTREVISION=	2
CATEGORIES=	news
#MASTER_SITES=	http://www.sucknews.org/
MASTER_SITES=	http://home.comcast.net/~bobyetman/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMESUFFIX?=	${CNEWS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receives/sends news to/from localhost via NNTP

CONFLICTS?=	suckblow-1.*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		suck.1 rpost.1 testhost.1 lmove.1
EX_SCRIPTS=	get.news.generic get.news.inn perl_kill.pl perl_xover.pl \
		post_filter.pl put.news put.news.pl put.news.sm put.news.sm.pl
EX_DATA=	suckkillfile.sample sucknewsrc.sample suckothermsgs.sample

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	CHKHISTORY=chkhistory_db.o

.if defined(NEWSBIN) && !defined(SUCK_WITH_INN)
CNEWS_PORT?=	news/cnews
CNEWS_SUFFIX=	-cnews
MAKE_ENV+=	DB_TYPE=-DUSE_DBZ DB_LIB=-lcnews
MAKE_ENV+=	DB_LIB_LOC=-L${LOCALBASE}/lib
MAKE_ENV+=	INCDIR2=-I${LOCALBASE}/include
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/${CNEWS_PORT}
CONFLICTS+=	suck-4.*
.else
CFLAGS+=	-DNO_CONFIGDATA
MAKE_ENV+=	DB_TYPE="-DUSE_INN23 -DDO_TAGGED_HASH"
MAKE_ENV+=	DB_LIB="-linn -lstorage"
MAKE_ENV+=	DB_LIB_LOC=-L${LOCALBASE}/news/lib
MAKE_ENV+=	DB_INC_LOC=-I${LOCALBASE}/news/include
MAKE_ENV+=	INCDIR2=-I${LOCALBASE}/include
BUILD_DEPENDS+=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
CONFLICTS+=	suck-cnews-4.*
.endif

.if !defined(SUCK_WITHOUT_SSL) && !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
MAKE_ENV+=	SSL_LIB="-lssl -lcrypto"
MAKE_ENV+=	SSL_DEFS="-I${OPENSSLINC} -DHAVE_LIBSSL"
MAKE_ENV+=	SSL_LIB_LOC="-L${OPENSSLLIB}"
.endif

post-patch:
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.sed
	${SED} -e "s=/usr/local/=${LOCALBASE}/=" \
		${WRKSRC}/Makefile.in.sed > ${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/suck_config.h ${WRKSRC}/suck_config.h.sed
.if defined(NEWSBIN) && !defined(SUCK_WITH_INN)
	${SED} -e "s=/usr/local/lib/suck=${PREFIX}/lib/suck=" \
		-e "s=/usr/local/news/lib=${NEWSCTL}=" \
		${WRKSRC}/suck_config.h.sed > ${WRKSRC}/suck_config.h
.else
	${SED} -e "s=/usr/local/lib/suck=${PREFIX}/lib/suck=" \
		-e "s=/usr/local/news/lib=${LOCALBASE}/news/lib=" \
		${WRKSRC}/suck_config.h.sed > ${WRKSRC}/suck_config.h
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in ${EX_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${i} ${EXAMPLESDIR}/
.endfor
.for i in ${EX_DATA}
	${INSTALL_DATA} ${WRKSRC}/sample/${i} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
