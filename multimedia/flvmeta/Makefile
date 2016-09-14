# Created by: Earl Gay <earl@eeg3.net>
# $FreeBSD$

PORTNAME=	flvmeta
PORTVERSION=	1.0.11
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	earl@eeg3.net
COMMENT=	Manipulation tool for Adobe Flash Video files (FLV)
 
BROKEN=		Unfetchable (google code has gone away)

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/flvmeta bin/flvdump

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
