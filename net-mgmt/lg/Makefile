# Created by: Mathieu Arnold <mat@freebsd.org>
# $FreeBSD$

PORTNAME=	lg
PORTVERSION=	1.9.s20140622
MASTER_SITES=	LOCAL/mat/lg GH GHC
CATEGORIES=	net-mgmt perl5

MAINTAINER=	mat@freebsd.org
COMMENT=	Looking Glass written in Perl as a CGI script

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Cougar
GH_COMMIT=	0d53e4b
GH_TAGNAME=	${GH_COMMIT}

USES=	perl5
USE_PERL5=	run

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/lg.cgi ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} lg.conf favicon.ico ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} makeaslist.pl makedb.pl ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} as.txt communities.txt ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG COPYING README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
