# $FreeBSD$

PORTNAME=	libotr
PORTVERSION=	4.0.0
# Please do not bump PORTREVISION for this port unless you have
# confirmed via testing that it is necessary
PORTREVISION=	2
CATEGORIES=	security net-im net
MASTER_SITES=	https://otr.cypherpunks.ca/ \
		http://www.c-s.li/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Portable OTR Messaging Library and toolkit

LICENSE=	LGPL21

BUILD_DEPENDS=	pkgconf>0:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS=	libotr3-*

USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#^pkgconfigdir .*#pkgconfigdir = ${PREFIX}/libdata/pkgconfig#' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

.if ${OSVERSION} >= 800000 && ${OSVERSION} < 1000000
	@${REINPLACE_CMD} -e 's#OTR_CHECK_CFLAGS(.*stack-protector.*#dnl &#' \
	    ${WRKSRC}/configure.ac
.endif

.include <bsd.port.post.mk>
