# New ports collection makefile for:	tpp
# Date created:				2004-08-30
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	tpp
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://synflood.at/tpp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text presentation program

RUN_DEPENDS=	${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses \
		figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes
USE_REINPLACE=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

MAN1=	tpp.1

post-patch:
	${REINPLACE_CMD} -e "s,/usr/bin,${PREFIX}/bin," ${WRKSRC}/tpp.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tpp.rb ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/tpp.rb ${PREFIX}/bin/tpp
	${INSTALL_MAN} ${WRKSRC}/doc/tpp.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} CHANGES COPYING README ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/examples
	cd ${WRKSRC}/examples; ${INSTALL_DATA} * ${DOCSDIR}/examples
.endif

.include <bsd.port.mk>
