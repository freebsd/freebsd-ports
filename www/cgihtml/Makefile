# New ports collection makefile for:	cgihtml
# Date created:		3 Nov 1997
# Whom:			Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	cgihtml
PORTVERSION=	1.69
PORTREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	http://www.eekim.com/software/cgihtml/ \
		ftp://www.eekim.com/pub/users/eekim/cgihtml/ \
		ftp://hcs.harvard.edu/pub/web/tools/cgihtml/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Library that simplifies the task of writing CGI programs in C

INSTALLS_SHLIB=	yes

post-extract:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cgihtml/html
.for file in CHANGES CREDITS
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cgihtml
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/cgihtml/html
.endif

.include <bsd.port.mk>
