# New ports collection makefile for:	LambdaMOO
# Date created:		Jul 3 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lambdamoo
PORTVERSION=	1.8.0.r8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.place.org/pub/moo/unofficial/
DISTNAME=	LambdaMOO-1.8.0r8

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
