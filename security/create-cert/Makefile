# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	create-cert
PORTVERSION=	2.3
CATEGORIES=	security
MASTER_SITES=	ftp://ee.lbl.gov/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Create openssl client key and certificates

LICENSE=	BSD

PLIST_FILES=	sbin/create-cert

MAN8=		create-cert.8

GNU_CONFIGURE=	yes

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

NO_STAGE=	yes
.include <bsd.port.mk>
