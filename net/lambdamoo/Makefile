# New ports collection makefile for:	LambdaMOO
# Date created:		Jul 3 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lambdamoo
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	LambdaMOO-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The most commonly used program to run MOOs

WRKSRC=		${WRKDIR}/MOO-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=
CONFIGURE_ENV=	YACC=${YACC}
USE_BISON=	build

PLIST_FILES=	sbin/moo

PORTDOCS=	*

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC};\
	${INSTALL_MAN} Minimal.db README README.Minimal \
		${DOCSDIR}; \
	)
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
