# $FreeBSD$

PORTNAME=	libotr
PORTVERSION=	4.0.0
# Please do not bump PORTREVISION for this port unless you have
# confirmed via testing that it is necessary
PORTREVISION=	2
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable OTR Messaging Library and toolkit

BUILD_DEPENDS=	pkgconf>0:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error \
		gcrypt:${PORTSDIR}/security/libgcrypt


CONFLICTS=	libotr-3.*

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
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#^pkgconfigdir .*#pkgconfigdir = ${PREFIX}/libdata/pkgconfig#' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

.if ${OSVERSION} >= 800000 && ${OSVERSION} < 1000000
	@${REINPLACE_CMD} -e 's#OTR_CHECK_CFLAGS(.*stack-protector.*#dnl &#' \
	    ${WRKSRC}/configure.ac
.endif

.include <bsd.port.post.mk>
