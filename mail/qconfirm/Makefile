# New ports collection makefile for:	qconfirm
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	qconfirm
PORTVERSION=	0.14.3
CATEGORIES=	mail
MASTER_SITES=	http://smarden.org/qconfirm/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Filter spam by requesting confirmation from sender

WRKSRC=		${WRKDIR}/mail/${DISTNAME}
ALL_TARGET=	default

MAN1=		qconfirm.1 qconfirm-accept.1 qconfirm-check.1 \
		qconfirm-check-mid.1 qconfirm-conf.1 \
		qconfirm-cdb-check.1 qconfirm-cdb-update.1 \
		qconfirm-control.1 qconfirm-inject.1 \
		qconfirm-notice.1 qconfirm-return.1
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
