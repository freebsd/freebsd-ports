# New ports collection makefile for:	bkmrkconv
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	bkmrkconv
PORTVERSION= 	1.08
CATEGORIES=	www
MASTER_SITES=	http://www.dcs.warwick.ac.uk/~csube/bkmrkconv/
DISTNAME=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

pre-install:
	@${PERL} -pi -e "s:/usr/local/bin/perl:${PERL}:g" ${WRKSRC}/*.pl
	@${PERL} -pi -e "s:/usr/local/share:${PREFIX}/share:g" ${WRKSRC}/bkmrkconv.pl

do-install:
	@${MKDIR} ${PREFIX}/share/bkmrkconv/src
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/bkmrkconv/
	@${INSTALL_DATA} ${WRKSRC}/src.example/* ${PREFIX}/share/bkmrkconv/src/
	@${INSTALL_SCRIPT} ${WRKSRC}/random.pl ${PREFIX}/share/bkmrkconv/
	@${INSTALL_SCRIPT} ${WRKSRC}/bkmrkconv.pl ${PREFIX}/bin/bkmrkconv

.include <bsd.port.mk>
