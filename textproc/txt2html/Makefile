# New ports collection makefile for:    txt2html
# Date created:         29 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	txt2html
PORTVERSION=	1.28
CATEGORIES=	textproc
MASTER_SITES=	http://www.aigeek.com/txt2html/

MAINTAINER=	croyle@gelemna.org

NO_BUILD=	yes

do-configure:
	cd ${WRKSRC} && perl -pi -e "s|/usr/local|${PREFIX}|g" txt2html.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2html.pl ${PREFIX}/bin/txt2html
	${MKDIR} ${PREFIX}/share/doc/txt2html
	${INSTALL_DATA} ${WRKSRC}/txt2html.dict ${PREFIX}/share/doc/txt2html/
.if !defined(NOPORTDOCS)
.for file in INSTALL LICENSE README changes.html sample.foot sample.html sample.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/txt2html/
.endfor
.endif
	@${ECHO_MSG} "To install the sample links dictionary as the default"
	@${ECHO_MSG} "copy or link ${PREFIX}/share/doc/txt2html/txt2html.dict to"
	@${ECHO_MSG} "${PREFIX}/lib/txt2html.dict or ~/.txt2html.dict"

.include <bsd.port.mk>
