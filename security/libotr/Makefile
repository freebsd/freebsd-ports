# ex:ts=8
# New ports collection makefile for:	libotr
# Date created:				2005-03-20
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	libotr
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.cypherpunks.ca/otr/ \
		http://dougbarton.us/Downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	The portable OTR Messaging Library and toolkit

LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error \
		gcrypt:${PORTSDIR}/security/libgcrypt

MAKE_JOBS_SAFE=	yes

USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	autoconf:262 libtool:22
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

post-patch:
	@${REINPLACE_CMD} -e 's#^pkgconfigdir .*#pkgconfigdir = ${PREFIX}/libdata/pkgconfig#' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
