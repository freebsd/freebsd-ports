# New ports collection makefile for:  jargon
# Date created: 	11 July 1998
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	jargon
PORTVERSION=	4.2.3
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/jargon/

MAINTAINER=	s.moeding@ndh.net

NO_BUILD=	YES

FILES=		alternates.html awards.html download.html index.html \
		jargbook.html jarghist.html jargon.html jargtxt.html \
		mirroring.html mirrorlist.html quoting.html search.html \
		submissions.html

post-patch:
	/usr/bin/perl -pi -e 's,/home/httpd/html,${PREFIX}/www/data,' ${WRKSRC}/jargon-search
do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/jargon-search ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/www/data/jargon
.for file in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/www/data/jargon
.endfor
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/www/data/jargon
	@${CP} -R ${WRKSRC}/graphics ${PREFIX}/www/data/jargon/
	@${CP} -R ${WRKSRC}/html ${PREFIX}/www/data/jargon/
	@${MKDIR} ${PREFIX}/share/doc/jargon
	@${INSTALL_DATA} ${WRKSRC}/jargon-README ${PREFIX}/share/doc/jargon

.include <bsd.port.mk>
