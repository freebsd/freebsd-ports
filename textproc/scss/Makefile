# Created by: ijliao
# $FreeBSD$

PORTNAME=	scss
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Scheme module for W3C Cascading Stylesheets recommendation

LICENSE=	GPLv3

RUN_DEPENDS=	guile:lang/guile

NO_BUILD=	yes

FILES=	lexer.scm parser.scm scss.scm properties.scm \
	interface/sdom.scm common.scm
INFO=	scss

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/guile/scss
.for f in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/guile/scss
.endfor
	@${INSTALL_DATA} ${WRKSRC}/scss.info ${STAGEDIR}${PREFIX}/info

.include <bsd.port.mk>
