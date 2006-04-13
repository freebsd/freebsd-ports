# New ports collection makefile for:	LambdaMOO
# Date created:		Jul 3 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lambdamoo
PORTVERSION=	1.8.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	LambdaMOO-${PORTVERSION}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	The most commonly used program to run MOOs

WRKSRC=		${WRKDIR}/MOO-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=
CONFIGURE_ENV=	YACC=${YACC}
USE_BISON=	yes

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
