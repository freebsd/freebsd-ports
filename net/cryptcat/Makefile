# Ports collection makefile for:  cryptcat
# Date created:			  20 Dec 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	cryptcat
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-unix-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard netcat enhanced with twofish encryption

WRKSRC=		${WRKDIR}/unix
ALL_TARGET=	freebsd

PLIST_FILES=	bin/cryptcat
PORTDOCS=	README.cryptcat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptcat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
