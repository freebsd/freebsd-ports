# ex:ts=8
# Ports collection makefile for:	SCSS
# Date created:			Mar 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scss
PORTVERSION=	0.3.2
PORTREVISION=	0
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme module for W3C Cascading Stylesheets recommendation

RUN_DEPENDS=	guile:${PORTSDIR}/lang/guile

NO_BUILD=	yes

FILES=	lexer.scm parser.scm scss.scm srfi-32.scm
PLIST_FILES=	share/guile/scss/lexer.scm \
		share/guile/scss/parser.scm \
		share/guile/scss/scss.scm \
		share/guile/scss/srfi-32.scm
PLIST_DIRS=	share/guile/scss

INFO=	scss

do-install:
	@${MKDIR} ${PREFIX}/share/guile/scss
.for f in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/guile/scss
.endfor
	@${INSTALL_DATA} ${WRKSRC}/scss.info ${PREFIX}/info

.include <bsd.port.mk>
