# $FreeBSD$

PORTNAME=	libotr
PORTVERSION=	3.2.1
# Please do not bump PORTREVISION for this port unless you have
# confirmed via testing that it is necessary
PORTREVISION=	1
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Portable OTR Messaging Library and toolkit

BUILD_DEPENDS=	pkgconf>0:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error \
		gcrypt:${PORTSDIR}/security/libgcrypt


NO_LATEST_LINK=	yes
CONFLICTS=	libotr-4.*

USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes

MAN1=		otr_toolkit.1
MLINKS=		otr_toolkit.1 otr_parse.1 \
		otr_toolkit.1 otr_sesskeys.1 \
		otr_toolkit.1 otr_mackey.1 \
		otr_toolkit.1 otr_readforge.1 \
		otr_toolkit.1 otr_modify.1 \
		otr_toolkit.1 otr_remac.1

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#^pkgconfigdir .*#pkgconfigdir = ${PREFIX}/libdata/pkgconfig#' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
