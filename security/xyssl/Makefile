# New ports collection makefile for:	xyssl
# Date created:				2007-04-05
# Whom:					mdh <mdh@solitox.net>
#
# $FreeBSD$
#

PORTNAME=	xyssl
PORTVERSION=	0.9
CATEGORIES=	security devel
MASTER_SITES=	http://www.evolane.com/download/mirror/etcl/ \
		http://www.straightrunning.com/code/
DISTFILES=	xyssl-${PORTVERSION}-bsd.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight SSL and TLS toolkit for C developers

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/BSD.txt

# HAS_CONFIGURE=	no
# GNU_CONFIGURE=	no

PORTDOCS=	BSD.txt ChangeLog

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/BSD.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
