# $FreeBSD$

PORTNAME=	lg
PORTVERSION=	1.9.s20140622
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	LOCAL/mat/lg \
		GH

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Looking Glass written in Perl as a CGI script

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Cougar
GH_TAGNAME=	0d53e4b

USE_PERL5=	run
SHEBANG_FILES=	lg.cgi makeaslist.pl makedb.pl

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

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
