# ex:ts=8
# Ports collection makefile for:	SCSS
# Date created:			Mar 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scss
PORTVERSION=	0.4.0
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A Scheme module for W3C Cascading Stylesheets recommendation

RUN_DEPENDS=	guile:${PORTSDIR}/lang/guile

LICENSE=	GPLv3

NO_BUILD=	yes

FILES=	lexer.scm parser.scm scss.scm properties.scm \
	interface/sdom.scm common.scm

INFO=	scss

do-install:
	@${MKDIR} ${PREFIX}/share/guile/scss
.for f in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/guile/scss
.endfor
	@${INSTALL_DATA} ${WRKSRC}/scss.info ${PREFIX}/info

.include <bsd.port.mk>
