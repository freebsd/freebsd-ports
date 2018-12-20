# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	gnuit
PORTVERSION=	4.9.5
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi

USES=		ncurses
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-transition
INFO=		gnuit

post-install:
	# Clean stage from orphans.
	${RM} ${STAGEDIR}${PREFIX}/man/man1/gitmkdirs.1
	${RM} ${STAGEDIR}${PREFIX}/man/man1/gitwhich.1
	${RM} ${STAGEDIR}${PREFIX}/man/man1/gitxgrep.1

.include <bsd.port.mk>
