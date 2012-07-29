# New ports collection makefile for:    bsfilter
# Date created:         1 Mar 2004
# Whom:                 Masafumi Otsune <info@otsune.com>
#
# $FreeBSD$
#

PORTNAME=	bsfilter
PORTVERSION=	1.0.17
CATEGORIES=	mail ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	bsfilter/49795
EXTRACT_SUFX=	.tgz

MAINTAINER=	info@otsune.com
COMMENT=	Bayesian spam filter written in Ruby

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes

OPTIONS=	CHASEN "Japanese Morphological Analysis Support" Off \
		MECAB "Part-of-Speech and Morphological Analyzer" Off

.include <bsd.port.pre.mk>

.if defined(WITH_CHASEN)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/chasen.so:${PORTSDIR}/japanese/ruby-chasen
.endif
.if defined(WITH_MECAB)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/MeCab.so:${PORTSDIR}/japanese/ruby-mecab
.endif

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
