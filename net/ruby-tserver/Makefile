# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tserver
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.tmtm.org/ruby/tserver/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for writing a preforking server like Apache

USE_RUBY=	yes
USES=		shebangfix

SHEBANG_FILES=	${WRKSRC}/sample/*

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/tserver.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/tommy.css ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
