# Ports collection makefile for:	pam_bsdbioapi
# Date created:				13 January 2006
# Whom:					Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	pam_bsdbioapi
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://shapeshifter.se/pub/pam_bsdbioapi/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	PAM module for BioAPI

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi

MAN8=		pam_bsdbioapi.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs at least FreeBSD 5.0-RELEASE
.endif

.include <bsd.port.post.mk>
