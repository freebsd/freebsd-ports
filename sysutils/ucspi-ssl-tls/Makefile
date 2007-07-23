# New ports collection makefile for:	ucspi-ssl-tls
# Date created:				2006-05-26
# Whom:					Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	2
PORTEPOCH=	0
PKGNAMESUFFIX=	-tls

MAINTAINER=	garga@FreeBSD.org
COMMENT=	UCSPI tools for building SSL client-server applications w/ TLS support

CONFLICTS=	ucspi-ssl-[0-9]*

PATCH_SITES+=		${MASTER_SITE_LOCAL:S/$/:tls/}
PATCH_SITE_SUBDIR+=	garga/ucspi-ssl/:tls
PATCHFILES+=		ucspi-ssl-0.70_ucspitls-0.4.patch:tls
PATCH_WRKSRC=		${WRKSRC}/src

MASTERDIR=	${.CURDIR}/../ucspi-ssl

.include "${MASTERDIR}/Makefile"
