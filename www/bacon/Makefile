# New ports collection makefile for:   bacon
# Date created:        9 September 1999
# Whom:                Justin Robinson <jmrobins@samurai.ruin.org>
#
# $FreeBSD$
#

PORTNAME=	bacon
PORTVERSION=	1.071999
CATEGORIES=	www
MASTER_SITES=	http://galileo.spaceports.com/~jharris/distfiles/ \
		ftp://samurai.ruin.org/pub/All/

MAINTAINER=	jmrobins@samurai.ruin.org

USE_PERL5=	yes
NO_BUILD=	yes

pre-patch:
	@${PERL} -pi.orig -e 's|${LOCALBASE}/bin/perl|${PERL}|' \
		${WRKSRC}/bacon.pl

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/bacon.pl ${PREFIX}/www/cgi-bin/bacon.pl

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif
	@${SED} -e "s|INSTALL|${DOCSDIR}/INSTALL|" ${PKGMESSAGE}

.include <bsd.port.mk>
