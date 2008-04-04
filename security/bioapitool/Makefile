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

DEPRECATED=	All functionallity of this tools has been merged with pam_bsdbioapi
EXPIRATION_DATE=2008-05-04

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi

MAN1=		bioapitool.1
PLIST_FILES=	sbin/bioapitool

.include <bsd.port.mk>
