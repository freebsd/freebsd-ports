# New ports collection makefile for:    bsfilter
# Date created:         1 Mar 2004
# Whom:                 Masafumi Otsune <info@otsune.com>
#
# $FreeBSD$
#

PORTNAME=	bsfilter
PORTVERSION=	1.0.4
CATEGORIES=	mail ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	bsfilter/10876
EXTRACT_SUFX=	.tgz

MAINTAINER=	info@otsune.com
COMMENT=	A bayesian spam filter written in Ruby

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes

OPTIONS=	MECAB "Use japanese/mecab" off \
		CHASEN "Use japanese/chasen" off \
		KAKASI "Use japanese/kakasi" off

.include <bsd.port.pre.mk>

.if defined(WITH_MECAB)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/MeCab.so:${PORTSDIR}/japanese/ruby-mecab
.endif
.if defined(WITH_KAKASI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/kakasi.so:${PORTSDIR}/japanese/ruby-kakasi
.endif

pre-build:
	@${ECHO_MSG} "specify algorithm of a tokenizer for Japanese language"
	@${ECHO_MSG} "WITH_CHASEN=yes (japanese/chasen)"
	@${ECHO_MSG} "WITH_KAKASI=yes (japanese/kakasi)"
	@${ECHO_MSG} "WITH_MECAB=yes (japanese/mecab)"

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in bsfilter.conf.sample dot-qmail.sample
	@${INSTALL_DATA} ${FILESDIR}/${FILE} ${EXAMPLESDIR}
.endfor
.for DIR in mda mua
	@${CP} -r ${WRKSRC}/${DIR} ${EXAMPLESDIR}/${DIR}
.endfor
.endif

.include <bsd.port.post.mk>
