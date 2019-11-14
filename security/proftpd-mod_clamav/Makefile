# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_clamav
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14rc2
PORTREVISION=	1
CATEGORIES=	security ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	ClamAV ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

GIT_REVISION=	c8586c7

RUN_DEPENDS+=	clamd:security/clamav
_PROFTPD_MODULE_DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${EXTRACT_SUFX}:clamav
_PROFTPD_MODULE_EXTRACT_ONLY=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${EXTRACT_SUFX}
_PROFTPD_MODULE_MASTER_SITES=	https://codeload.github.com/jbenden/mod_clamav/legacy.tar.gz/v${DISTVERSION}?dummy=/:clamav

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

post-extract:
	@${CP} ${WRKDIR}/jbenden-mod_clamav-${GIT_REVISION}/mod_clamav.* ${WRKSRC}/contrib

.include "${MASTERDIR}/Makefile"
