# New ports collection makefile for:	slirp
# Date created:		25 Aug 1995
# Whom:			Alain Kalker <A.C.P.M.Kalker@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	slirp
PORTVERSION=	1.0.14.p1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=slirp
DISTNAME=	${PORTNAME}-1.0.14pre1
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A (C)SLIP/PPP emulator for users with shell accounts

# serious LP64 issues
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes

MAN1=		slirp.1
PLIST_FILES=	bin/slirp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slirp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slirp.man ${PREFIX}/man/man1/slirp.1

.include <bsd.port.mk>
