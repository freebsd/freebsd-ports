# New ports collection makefile for:	cdlabelgen
# Date created:		Tue Jun 23 00:19:55 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	cdlabelgen
PORTVERSION=	3.5.0
CATEGORIES=	print perl5
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Generate postscript for frontcards and traycards for CDs

MAN1=		cdlabelgen.1
MANCOMPRESSED=	no

USE_PERL5=	yes
MAKE_ARGS=	BASE_DIR="${PREFIX}" \
		LIB_DIR="${DATADIR}" \
		INSTALL="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILE="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"

do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${WRKSRC}/cdlabelgen

.include <bsd.port.mk>
