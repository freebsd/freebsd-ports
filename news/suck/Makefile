# New ports collection makefile for:	suck
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $FreeBSD$
#

PORTNAME=	suck
PORTVERSION=	4.3.0
CATEGORIES=	news
MASTER_SITES=	http://www.sucknews.org/

MAINTAINER=	dinoex@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
.if defined(SUCK_WITH_SSL) || defined(WITH_SSL)
USE_OPENSSL=	yes
.endif
MAN1=		suck.1 rpost.1 testhost.1 lmove.1
EX_SCRIPTS=	get.news.generic get.news.inn perl_kill.pl perl_xover.pl \
		post_filter.pl put.news put.news.pl put.news.sm put.news.sm.pl
EX_DATA=	suckkillfile.sample sucknewsrc.sample suckothermsgs.sample

.if defined(NEWSBIN)
PKGNAMESUFFIX=	-cnews
EXTRA_PATCHES+=	${FILESDIR}/cnews.patch
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/news/cnews
.else
EXTRA_PATCHES+=	${FILESDIR}/inn2.patch
BUILD_DEPENDS+=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
.endif

.include <bsd.port.pre.mk>

.if defined(SUCK_WITH_SSL) || defined(WITH_SSL)
USE_OPENSSL=	yes
.if ${OSVERSION} < 430000
OPENSSLBASE=	/usr/local
OPENSSLDIR=	${OPENSSLBASE}/openssl
LIB_DEPENDS+=   crypto.2:${PORTSDIR}/security/openssl
OPENSSLLIB=	${OPENSSLBASE}/lib
OPENSSLINC=	${OPENSSLBASE}/include
.endif
MAKE_ENV+=	SSL_LIB="-lssl -lcrypto"
MAKE_ENV+=	SSL_DEFS="-I${OPENSSLINC} -DHAVE_LIBSSL"
MAKE_ENV+=	SSL_LIB_LOC="-L${OPENSSLLIB}"
.endif

post-patch:
	@${PERL5} -pi -e "s=/usr/local/=${LOCALBASE}/=" ${WRKSRC}/Makefile.in
	@${PERL5} -pi -e "s=/usr/local/lib/suck=${PREFIX}/lib/suck=" \
		${WRKSRC}/suck_config.h
	@${PERL5} -pi -e "s=/usr/local/news/lib=${LOCALBASE}/news/lib=" \
		${WRKSRC}/suck_config.h

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

.include <bsd.port.post.mk>
