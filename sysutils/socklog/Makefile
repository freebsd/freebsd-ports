# New ports collection makefile for:	socklog
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	socklog
PORTVERSION=	0.10.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://smarden.org/socklog/

MAINTAINER=	sergei@kolobov.com

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src
ALL_TARGET=	default

PROGS=		socklog-conf socklog tryto uncat
.if !defined(NOPORTDOCS)
MAN1=		tryto.1 uncat.1
MAN8=		socklog-conf.8 socklog.8
.endif

do-install:
.for file in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${MANPREFIX}/man/man1
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../man/${file} ${MANPREFIX}/man/man1
.endfor
	${MKDIR} ${MANPREFIX}/man/man8
.for file in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/../man/${file} ${MANPREFIX}/man/man8
.endfor
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
