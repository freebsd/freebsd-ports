# New ports collection makefile for:	bkmrkconv
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	bkmrkconv
PORTVERSION=	1.10
CATEGORIES=	www
MASTER_SITES=	http://www.bleb.org/software/bkmrkconv/

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@find ${WRKSRC} -name '*.pl' | xargs ${PERL} -pi -e \
		's|/usr/bin/perl|${PERL}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bkmrkconv.pl ${PREFIX}/bin/bkmrkconv
	@${MKDIR} ${PREFIX}/share/bkmrkconv/src
	${INSTALL_SCRIPT} ${WRKSRC}/utils/* ${PREFIX}/share/bkmrkconv
	${INSTALL_DATA} ${WRKSRC}/src.example/* ${PREFIX}/share/bkmrkconv/src
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bkmrkconv
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/bkmrkconv
.endif

.include <bsd.port.mk>
