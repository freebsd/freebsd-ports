# New ports collection makefile for:	create-cert
# Date created:		2011-02-24
# Whom:			Craig Leres <leres@ee.lbl.gov>
#
# $FreeBSD$
#

PORTNAME=	create-cert
PORTVERSION=	2.2
CATEGORIES=	security
MASTER_SITES=	ftp://ee.lbl.gov/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Create openssl client key and certificates

PLIST_FILES=	sbin/create-cert

MAN8=		create-cert.8

GNU_CONFIGURE=	yes

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

LICENSE=	BSD

.include <bsd.port.mk>
