# New ports collection makefile for:  enteruser
# Date created:         19 Feb 2002
# Whom:                 Danny Howard <dannyman@toldme.com>
#
# $FreeBSD$
#

PORTNAME=	enteruser
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dannyman.toldme.com/warez/
DISTNAME=	enteruser
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dannyman@toldme.com
COMMENT=	Extensible script for adding new users

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_WRKSUBDIR=	true
NO_BUILD=	true

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-patch:
	@${REINPLACE_CMD} -e 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/enteruser

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/enteruser ${PREFIX}/sbin
	${LN} -f ${PREFIX}/sbin/enteruser ${PREFIX}/sbin/queueuser

.include <bsd.port.mk>
