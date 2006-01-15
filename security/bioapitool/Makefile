# Ports collection makefile for:	bioapitool
# Date created:				12 January 2006
# Whom:					Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	bioapitool
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://shapeshifter.se/pub/bioapitool/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	BioAPI management utility

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi

MAN1=		bioapitool.1
PLIST_FILES=	sbin/bioapitool

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs at least FreeBSD 5.0-RELEASE
.endif

.include <bsd.port.post.mk>
