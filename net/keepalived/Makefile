# New ports collection makefile for:	keepalived
# Date created:				Aug 25 2005
# Whom:					clement@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	keepalived
PORTVERSION=	1.1.11
CATEGORIES=	net
MASTER_SITES=	http://www.cultdeadsheep.org/~clement/FreeBSD/ipvs/
DISTNAME=	${PORTNAME}-FreeBSD-${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A monitoring daemon for ipvs clusters

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	${LOCALBASE}/lib/libipvs.a:${PORTSDIR}/net/ipvs

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_OPENSSL=	YES
USE_RC_SUBR=	keepalived.sh

LDFLAGS+=	-lipvs -L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-kernel-dir=${LOCALBASE} \
		--mandir=${PREFIX}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=	genhash.1
MAN5=	keepalived.conf.5
MAN8=	keepalived.8

post-patch:
	@${REINPLACE_CMD} 's,\(#define CONF\).*,\
		\1 "${PREFIX}/etc/keepalived/keepalived.conf",' \
		${WRKSRC}/lib/parser.h

post-install:
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	@if [ ! -e ${PREFIX}/etc/${PORTNAME}/keepalived.conf ] ; then \
		${INSTALL_DATA} ${EXAMPLESDIR}/keepalived.conf \
		${PREFIX}/etc/${PORTNAME}/keepalived.conf; fi

.include <bsd.port.mk>
