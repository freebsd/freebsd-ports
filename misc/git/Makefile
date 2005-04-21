# New ports collection makefile for:	git
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	4.3.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 \
		gitrgrep.1 gitunpack.1
INFO=		git

pre-patch:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25

.include <bsd.port.mk>
