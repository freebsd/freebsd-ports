# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	cdlabelgen
PORTVERSION=	4.2.0
CATEGORIES=	print perl5
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Generate postscript for frontcards and traycards for CDs

MAN1=		cdlabelgen.1
MANCOMPRESSED=	no

USES=		perl5
MAKE_ARGS=	BASE_DIR="${PREFIX}" \
		LIB_DIR="${DATADIR}" \
		INSTALL="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILE="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		MAN_DIR="${PREFIX}/man"

NO_STAGE=	yes
do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${WRKSRC}/cdlabelgen

.include <bsd.port.mk>
