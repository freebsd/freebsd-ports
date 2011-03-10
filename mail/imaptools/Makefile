# New ports collection makefile for:	mail/imaptools
# Date created:				2010-10-26
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	imaptools
PORTVERSION=	1.92
CATEGORIES=	mail
MASTER_SITES=	http://www.athensfbc.com/imap_tools/files/
DISTNAME=	imap_tools_V${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A number of tools and scripts for use with IMAP servers

LICENSE=	ISCL
LICENSE_FILE=	${WRKDIR}/license.txt

FETCH_ARGS=	-pRr
USE_PERL5_RUN=	yes

do-build:
	${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|g' ${WRKDIR}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.pl ${PREFIX}/bin

.include <bsd.port.mk>
