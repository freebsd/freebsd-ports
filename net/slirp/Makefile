# New ports collection makefile for:	slirp
# Date created:		25 Aug 1995
# Whom:			Alain Kalker <A.C.P.M.Kalker@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	slirp
PORTVERSION=	1.0.13
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=slirp

MAINTAINER=	ports@FreeBSD.Org

PORTCOMMENT=	A SLIP/CSLIP emulator for users with shell accounts

BUILD_DEPENDS=	perl:${PORTSDIR}/lang/perl5

# serious LP64 issues
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

MAN1=		slirp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slirp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slirp.man ${PREFIX}/man/man1/slirp.1

.include <bsd.port.mk>
