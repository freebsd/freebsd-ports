# Created by: Masafumi Otsune <info@otsune.com>
# $FreeBSD$

PORTNAME=	bsfilter
PORTVERSION=	1.0.19
CATEGORIES=	mail ruby
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	bsfilter/59804
EXTRACT_SUFX=	.tgz

MAINTAINER=	yasu@utahime.org
COMMENT=	Bayesian spam filter written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}gdbm>=0:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes
USES=		shebangfix
SHEBANG_FILES=	bsfilter/bsfilter

OPTIONS_DEFINE=	EXAMPLES MECAB

MECAB_DESC=	Part-of-Speech and Morphological Analyzer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMECAB}
RUN_DEPENDS+=	ja-${RUBY_PKGNAMEPREFIX}mecab>=0:${PORTSDIR}/japanese/ruby-mecab
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for FILE in bsfilter.conf.sample dot-qmail.sample
	@${INSTALL_DATA} ${FILESDIR}/${FILE} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for DIR in mda mua
	@${CP} -r ${WRKSRC}/${DIR} ${STAGEDIR}${EXAMPLESDIR}/${DIR}
.endfor

.include <bsd.port.mk>
