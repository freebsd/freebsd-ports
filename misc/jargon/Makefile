# New ports collection makefile for:  jargon
# Date created: 	11 July 1998
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	jargon
PORTVERSION=	4.1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/jargon/                     \
		http://www.nectar.com/distfiles/

MAINTAINER=	s.moeding@ndh.net

USE_PERL5=	YES
NO_BUILD=	YES

FILES=		jarghist.html mirroring.html alternates.html jarginfo.html mirrorlist.html awards.html quoting.html search.html jargon-upd.lst submissions.html index.html jargtxt.html

post-patch:
	${PERL} -pi -e 's,/home/httpd/html,${PREFIX}/www/data,' ${WRKSRC}/jargon-search

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/jargon-search ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/www/data/jargon
.for file in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/www/data/jargon
.endfor
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/www/data/jargon
	@${CP} -R ${WRKSRC}/graphics ${PREFIX}/www/data/jargon/
	@${CP} -R ${WRKSRC}/frames ${PREFIX}/www/data/jargon/
	@${CP} -R ${WRKSRC}/noframes ${PREFIX}/www/data/jargon/
	@${MKDIR} ${PREFIX}/share/doc/jargon
	@${INSTALL_DATA} ${WRKSRC}/jargon-README ${PREFIX}/share/doc/jargon

.include <bsd.port.mk>
