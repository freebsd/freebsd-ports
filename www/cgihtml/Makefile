# New ports collection makefile for:	cgihtml
# Version required:     1.69
# Date created:		3 Nov 1997
# Whom:			Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $Id: Makefile,v 1.1.1.1 1998/06/14 12:38:55 jseger Exp $
#

DISTNAME=	cgihtml-1.69
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.eekim.com/users/eekim/cgihtml/

MAINTAINER=	i.vaudrey@bigfoot.com

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
