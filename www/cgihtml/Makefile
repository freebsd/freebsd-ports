# New ports collection makefile for:	cgihtml
# Date created:		3 Nov 1997
# Whom:			Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	cgihtml
PORTVERSION= 	1.69
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.eekim.com/pub/users/eekim/cgihtml/

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
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
