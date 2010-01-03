# New ports collection makefile for:	unstow
# Date created:		3 January 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	unstow
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.github.com/ \
		ftp://ftp.iDaemons.org/pub/distfiles/
DISTNAME=	knu-stow-utils-885c88a

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A script to unstow packages much faster than stow -D

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${MANPREFIX}/man/man1/
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
