# Created by: ache
# $FreeBSD$

PORTNAME=	sarep
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://sunsite.unc.edu/pub/linux/utils/text/
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line search and replace tool; written in Perl; handles regexps

RUN_DEPENDS=	p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS

EXTRACT_CMD=	$(SED)
EXTRACT_BEFORE_ARGS=	's=^\#!/usr/bin/perl =\#!${PERL} =' <
EXTRACT_AFTER_ARGS=	| ${TR} -d '\r' > ${WRKSRC}/sarep

USES=		perl5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/sarep

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sarep ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
