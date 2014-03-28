# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	samidare
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.a-k-r.org/${PORTNAME}/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/samidare|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A web page update checker written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/htree.rb:${PORTSDIR}/textproc/ruby-htree \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv

USES=		gmake
USE_RUBY=	yes

RUBY_REQUIRE=	Ruby >= 181
RUBY_SHEBANG_FILES=	main.rb rb-link rb2rm rm2rb
PORTDOCS=	README README.ja
PORTEXAMPLES=	config.yml t.latest.html

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		requires Ruby 1.8.1 or later
.endif

ALL_TARGET=	${PORTNAME}
MAN1=	${PORTNAME}.1

post-build:
	@${REINPLACE_CMD} -e '1d' ${BUILD_WRKSRC}/${PORTNAME}
	@cd ${BUILD_WRKSRC}; ${MV} ${PORTNAME}.man ${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${INSTALL_WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
