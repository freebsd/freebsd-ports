# New ports collection makefile for: ifdepd
# Date created:         03 03 2005
# Whom:                 Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	ifdepd
PORTVERSION=	20050303
CATEGORIES=	net
MASTER_SITES=	http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Interface Dependancy daemon

INSTALL_TARGET=	install install-man
MAN8=		ifdepd.8
MANCOMPRESSED=	no

PLIST_FILES=	bin/ifdepd \
		etc/rc.d/ifdepd.sh

USE_REINPLACE=	yes
PKGMESSAGE=	pkg-message

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502113
IGNORE=		need link state change notification changes from May 2004
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
