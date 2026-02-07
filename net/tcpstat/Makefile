PORTNAME=	tcpstat
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.frenchfries.net/paul/tcpstat/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Program to report various network statistics
WWW=		https://www.frenchfries.net/paul/tcpstat/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/tcpstat bin/tcpprof \
		share/man/man1/tcpprof.1.gz share/man/man1/tcpstat.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README doc/Tips_and_Tricks.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
