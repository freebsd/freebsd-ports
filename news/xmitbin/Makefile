# New ports collection makefile for:    xmitnin
# Date created:         29 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmitbin
PORTVERSION=	1.9
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.cadence.com/utils/
DISTNAME=	xmitBin-1.9
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Posts or mails binary and sourcecode files intelligently

MAN1=		xmitBin.1
NO_WRKSUBDIR=	YES

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
