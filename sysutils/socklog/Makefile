# New ports collection makefile for:	socklog
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	socklog
PORTVERSION=	1.0.0
CATEGORIES=	sysutils net
MASTER_SITES=	http://smarden.org/socklog/

MAINTAINER=	sergei@kolobov.com
COMMENT=	Small and secure replacement for syslogd

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src
ALL_TARGET=	default

PROGS=		socklog-conf socklog tryto uncat
MAN1=		tryto.1 uncat.1
MAN8=		socklog-conf.8 socklog.8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	@${MKDIR} ${MANPREFIX}/man/man1 ${MANPREFIX}/man/man8
	cd ${WRKSRC}/../man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/../man && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
