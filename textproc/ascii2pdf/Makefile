# New ports collection makefile for:   ascii2pdf
# Date created:        20 January 2001
# Whom:                petef@databits.net
#
# $FreeBSD$
#

PORTNAME=	ascii2pdf
PORTVERSION= 	0.9.1
CATEGORIES=	textproc
MASTER_SITES=	http://bulldog.tzo.org/ascii2pdf/
DISTNAME=	${PORTNAME}-0.9.1

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A perl script to convert text files to PDF files

RUN_DEPENDS=    ${SITE_PERL}/PDF/Create.pm:${PORTSDIR}/textproc/p5-PDF-Create

NO_BUILD=	yes
PLIST_FILES=	bin/ascii2pdf

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/ascii2pdf ${PREFIX}/bin

.include <bsd.port.post.mk>
