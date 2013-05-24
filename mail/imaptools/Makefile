# Created by: bsam
# $FreeBSD$

PORTNAME=	imaptools
PORTVERSION=	1.135
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bsam
DISTNAME=	imap_tools_V${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Tools and scripts to use with IMAP servers

LICENSE=	ISCL
LICENSE_FILE=	${WRKDIR}/license.txt

CONFLICTS=	imaputils-[0-9]*

USE_PERL5_RUN=	yes

do-build:
	${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|g' ${WRKDIR}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.pl ${PREFIX}/bin

.include <bsd.port.mk>
