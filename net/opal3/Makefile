# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	opal
PORTVERSION=	2.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src-
EXTRACT_SUFX=	tar.gz

MAINTAINER=	jbq@caraldi.com
COMMENT=	VoIP abstraction library

LIB_DEPENDS=	pt_r.1:${PORTSDIR}/devel/pwlib

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
