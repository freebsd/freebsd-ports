# New ports collection makefile for:    bsfilter
# Date created:         1 Mar 2004
# Whom:                 Masafumi Otsune <info@otsune.com>
#
# $FreeBSD$
#

PORTNAME=	bsfilter
PORTVERSION=	1.0.0
CATEGORIES=	mail ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	bsfilter/8453
EXTRACT_SUFX=	.tgz

MAINTAINER=	info@otsune.com
COMMENT=	A bayesian spam filter written in Ruby

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm
.if defined(WITH_MECAB)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/MeCab.so:${PORTSDIR}/japanese/ruby-mecab
.endif
.if defined(WITH_CHASEN)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/chasen.so:${PORTSDIR}/japanese/ruby-chasen
.endif
.if defined(WITH_KAKASI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/kakasi.so:${PORTSDIR}/japanese/ruby-kakasi
.endif

NO_BUILD=	yes
USE_RUBY=	yes

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
.endif

.include <bsd.port.mk>
