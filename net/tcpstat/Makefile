# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	tcpstat
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	http://www.frenchfries.net/paul/tcpstat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to report various network statistics

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tcpstat bin/tcpprof \
		man/man1/tcpprof.1.gz man/man1/tcpstat.1.gz

PORTDOCS=	*

DOCS=		AUTHORS ChangeLog README doc/Tips_and_Tricks.txt
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
