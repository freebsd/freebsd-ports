# New ports collection makefile for:	qlogtools
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	qlogtools
PORTVERSION=	3.1
PORTCOMMENT=	Tools for processing logs from qmail and other packages
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/qlogtools/

MAINTAINER=	sergei@kolobov.com

MAN1=		multipipe.1 multitail.1 qfilelog.1 \
		spipe.1 tai2tai64n.1 tai64n2tai.1 teepipe.1

pre-build:
	${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man

do-install:
	cd ${WRKSRC} && ./installer

.include <bsd.port.mk>
