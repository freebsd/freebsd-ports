# New ports collection makefile for:	delatt
# Date created:				22 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	delatt
DISTVERSION=	1.1.3
CATEGORIES=	mail
MASTER_SITES=	http://danborn.net/delatt/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Strip attachments from email

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

USE_PERL5_RUN=	5.8.6+
NO_BUILD=	yes

PLIST_FILES=	bin/delatt

post-patch:
	${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
