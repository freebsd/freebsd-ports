# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	firmware
PORTVERSION=	20140418
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	#none
PKGNAMEPREFIX=	sigrok-
PKGNAMESUFFIX=	-utils
DISTFILES=	#none

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Sigrok firmware extraction utils

LICENSE=	GPLv2

USES=		python:3.4+
NO_BUILD=	yes

PORTDOCS=	README.parsepe

PY_FILES=	parsepe.py parseelf.py

EX_FILES=	sigrok-fwextract-hantek-dso \
		sigrok-fwextract-saleae-logic16 \
		sigrok-fwextract-sysclk-lwla

PLIST_FILES=	${PY_FILES:S,^,bin/,} \
		${EX_FILES:S,^,bin/,} \
		${EX_FILES:S,^,man/man1/,:S,$,.1.gz,}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/README.parsepe ${STAGEDIR}${DOCSDIR}
.for fil in ${PY_FILES}
	${INSTALL_SCRIPT} ${FILESDIR}/${fil} ${STAGEDIR}${PREFIX}/bin
.endfor
.for fil in ${EX_FILES}
	${INSTALL_SCRIPT} ${FILESDIR}/${fil} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${fil}.1 ${STAGEDIR}${MANDIRS}/man1
.endfor

.include <bsd.port.mk>
