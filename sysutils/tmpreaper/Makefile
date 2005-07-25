# New ports collection makefile for:	tmpreaper
# Date created:				21 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	tmpreaper
PORTVERSION=	1.6.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Cleans up files in directories based on their age

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/tmpreaper
PORTDOCS=	README
MAN8=		tmpreaper.8

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
