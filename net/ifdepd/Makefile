# New ports collection makefile for: ifdepd
# Date created:         03 03 2005
# Whom:                 Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	ifdepd
PORTVERSION=	20050420
CATEGORIES=	net
MASTER_SITES=	http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Interface Dependancy daemon

MAN8=		ifdepd.8

PLIST_FILES=	bin/ifdepd \
		etc/rc.d/ifdepd.sh

USE_REINPLACE=	yes
USE_RC_SUBR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502113
IGNORE=		need link state change notification changes from May 2004
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/rc\.subr|${RC_SUBR}|; s|/usr/local|${PREFIX}|' \
		${WRKSRC}/ifdepd.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
