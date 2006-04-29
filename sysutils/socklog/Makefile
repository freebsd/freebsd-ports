# New ports collection makefile for:	socklog
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	socklog
PORTVERSION=	2.1.0
CATEGORIES=	sysutils net
MASTER_SITES=	http://smarden.org/socklog/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Small and secure replacement for syslogd

RUN_DEPENDS=	${LOCALBASE}/sbin/chpst:${PORTSDIR}/sysutils/runit

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
ALL_TARGET=	default

MAN1=		tryto.1 uncat.1
MAN8=		socklog-check.8 socklog-conf.8 socklog.8
DOCS=		package/CHANGES package/COPYING package/README doc/*.html

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc

do-build:
	cd ${WRKSRC} && package/compile
	@${ECHO_MSG} "Type 'make test' to run self-tests"

test:
	cd ${WRKSRC} && package/check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
