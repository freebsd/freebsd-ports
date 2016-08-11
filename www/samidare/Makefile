# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	samidare
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.a-k-r.org/${PORTNAME}/ \
		LOCAL/tota/samidare

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web page update checker written in Ruby

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${RUBY_SITELIBDIR}/htree.rb:textproc/ruby-htree

USES=	gmake shebangfix
USE_RUBY=	yes

SHEBANG_FILES=	main.rb rb-link rb2rm rm2rb
PORTDOCS=	README README.ja
PORTEXAMPLES=	config.yml t.latest.html

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/samidare man/man1/samidare.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

post-build:
	@${REINPLACE_CMD} -e '1d' ${BUILD_WRKSRC}/${PORTNAME}
	@cd ${BUILD_WRKSRC}; ${MV} ${PORTNAME}.man ${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${INSTALL_WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
