# New ports collection makefile for:	LambdaMOO
# Version required:	1.8.0r8
# Date created:		Jul 3 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	LambdaMOO-1.8.0r8
PKGNAME=	lambdamoo-1.8.0r8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.place.org/pub/moo/unofficial/

MAINTAINER=	flathill@FreeBSD.ORG

WRKSRC=		${WRKDIR}/MOO-1.8.0r8
GNU_CONFIGURE=	yes
ALL_TARGET=

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/LambdaMOO
	@(cd ${WRKSRC};\
	${INSTALL_MAN} Minimal.db README README.Minimal \
		${PREFIX}/share/doc/LambdaMOO; \
	)
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD \
		${PREFIX}/share/doc/LambdaMOO
.endif

.include <bsd.port.mk>
