# New ports collection makefile for:	qconfirm
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	qconfirm
PORTVERSION=	0.7.1
CATEGORIES=	mail
MASTER_SITES=	http://smarden.org/qconfirm/

MAINTAINER=	sergei@kolobov.com

WRKSRC=		${WRKDIR}/mail/${DISTNAME}/src
ALL_TARGET=	default

PROGS=		qconfirm qconfirm-accept qconfirm-check qconfirm-conf \
		qconfirm-control qconfirm-return
MAN1=		qconfirm.1 qconfirm-accept.1 qconfirm-check.1 qconfirm-conf.1 \
		qconfirm-control.1 qconfirm-return.1

do-install:
.for file in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../man/${file} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
