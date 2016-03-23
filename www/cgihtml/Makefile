# Created by: Ian Vaudrey <i.vaudrey@bigfoot.com>
# $FreeBSD$

PORTNAME=	cgihtml
PORTVERSION=	1.69
PORTREVISION=	3
CATEGORIES=	www devel
MASTER_SITES=	http://www.eekim.com/software/cgihtml/ \
		ftp://www.eekim.com/pub/users/eekim/cgihtml/ \
		ftp://hcs.harvard.edu/pub/web/tools/cgihtml/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library that simplifies the task of writing CGI programs in C

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgihtml.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for file in CHANGES CREDITS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
