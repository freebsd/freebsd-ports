# New ports collection makefile for:	xacpim
# Date created:				25 April 2004
# Whom:					henriknj@0xmilk.org
#
# $FreeBSD$

PORTNAME=	xacpim
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://shapeshifter.se/code/xacpim/release/ \
		http://0xcoffe.dk/mirror/xacpim/release/

MAINTAINER=	henriknj@0xmilk.org
COMMENT=	Utility to display battery status and temperature on the root-display

USE_X_PREFIX=	yes
PLIST_FILES=	bin/xacpim

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xacpim ${PREFIX}/bin/xacpim

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
IGNORE=		"4.x doesn\'t support ACPI"
.endif
.include <bsd.port.post.mk>
