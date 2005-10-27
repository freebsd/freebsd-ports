# Ports collection makefile for:  cryptcat
# Date created:			  20 Dec 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	cryptcat
PORTVERSION=	20031202
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@oven.org
COMMENT=	Standard netcat enhanced with twofish encryption

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
