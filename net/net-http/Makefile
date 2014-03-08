# Created by: ijliao
# $FreeBSD$

PORTNAME=	net-http
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	net scheme
MASTER_SITES=	http://evan.prodromou.name/software/net-http/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for doing HTTP client-side programming in Guile

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

GUILE_VER!=	${MAKE} -C ${PORTSDIR}/lang/guile -V GUILE_VER
PLIST_SUB=	GUILE_VER="${GUILE_VER}"

do-install:
	${CP} -R ${WRKSRC}/net/ ${LOCALBASE}/share/guile/${GUILE_VER}/net/

.include <bsd.port.mk>
