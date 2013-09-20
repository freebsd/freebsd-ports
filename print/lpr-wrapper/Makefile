# Created by: e-masson@kisoft-services.com
# $FreeBSD$

PORTNAME=	lpr-wrapper
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/lpr-wrapper/download/

MAINTAINER=	emss@free.fr
COMMENT=	A user level printer frontend

USE_GHOSTSCRIPT_RUN=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	ppdfilt:${PORTSDIR}/print/libppd
RUN_DEPENDS+=	psdim:${PORTSDIR}/print/psdim
RUN_DEPENDS+=	mpage:${PORTSDIR}/print/mpage
RUN_DEPENDS+=	pstops:${PORTSDIR}/print/psutils

PLIST_FILES=	bin/lpr-wrapper bin/lpr-wrapper-cups bin/lpr-wrapper-features

NO_STAGE=	yes
post-build:
	${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|' \
		${WRKSRC}/lpr-wrapper ${WRKSRC}/lpr-wrapper-cups \
		${WRKSRC}/lpr-wrapper-features

.include <bsd.port.mk>
