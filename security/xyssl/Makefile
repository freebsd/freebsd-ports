# New ports collection makefile for:	xyssl
# Date created:				2007-04-05
# Whom:					mdh <mdh@solitox.net>
#
# $FreeBSD$
#

PORTNAME=	xyssl
PORTVERSION=	0.9
CATEGORIES=	security devel
MASTER_SITES=	http://polarssl.org/code/download/ \
		ftp://ftp.solitox.net/pub/XySSL/
DISTFILES=	xyssl-${PORTVERSION}-bsd.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A liteweight SSL and TLS toolkit for C developers

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# HAS_CONFIGURE=	no
# GNU_CONFIGURE=	no

PORTDOCS=	BSD.txt ChangeLog

post-extract:
	${LN} ${WRKSRC}/BSD.txt ${WRKSRC}/COPYRIGHT

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/BSD.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
