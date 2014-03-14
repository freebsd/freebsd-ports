# Created by: Alain Kalker <A.C.P.M.Kalker@student.utwente.nl>
# $FreeBSD$

PORTNAME=	slirp
PORTVERSION=	1.0.16
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A (C)SLIP/PPP emulator for users with shell accounts

# serious LP64 issues
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/slirp man/man1/slirp.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slirp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slirp.man ${STAGEDIR}${PREFIX}/man/man1/slirp.1

.include <bsd.port.mk>
