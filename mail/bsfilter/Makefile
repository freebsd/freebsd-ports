# Created by: Masafumi Otsune <info@otsune.com>
# $FreeBSD$

PORTNAME=	bsfilter
PORTVERSION=	1.0.17
CATEGORIES=	mail ruby
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	bsfilter/49795
EXTRACT_SUFX=	.tgz

MAINTAINER=	info@otsune.com
COMMENT=	Bayesian spam filter written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}gdbm>=0:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes

OPTIONS_DEFINE=	CHASEN DOCS MECAB

CHASEN_DESC=	Japanese Morphological Analysis Support
MECAB_DESC=	Part-of-Speech and Morphological Analyzer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHASEN}
RUN_DEPENDS+=	ja-${RUBY_PKGNAMEPREFIX}chasen>=0:${PORTSDIR}/japanese/ruby-chasen
.endif
.if ${PORT_OPTIONS:MMECAB}
RUN_DEPENDS+=	ja-${RUBY_PKGNAMEPREFIX}mecab>=0:${PORTSDIR}/japanese/ruby-mecab
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.mk>
