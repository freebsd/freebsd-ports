# New ports collection makefile for:	flvmeta
# Date created:		31 July 2009
# Whom:			Earl Gay <earl@eeg3.net>
#
# $FreeBSD$
#

PORTNAME=	flvmeta
PORTVERSION=	1.0.10
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	earl@eeg3.net
COMMENT=	Manipulation tool for Adobe Flash Video files (FLV)

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/flvmeta bin/flvdump

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
