# New ports collection makefile for:	postfix-gps
# Date created:				2 September 2004
# Whom:					Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	0.9
CATEGORIES=	mail security
MASTER_SITES=	http://mimo.gn.apc.org/gps/
PKGNAMEPREFIX=	postfix-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}	\
		${SCRIPT_FILES}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Greylist Policy Service for postfix

BROKEN=		Broken dependency

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi
RUN_DEPENDS=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers

SCRIPT_FILES=	gps-maintain.pl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOCONF_VER=	259
USE_AUTOMAKE_VER=	19
USE_GCC=	3.3
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec --includedir=${PREFIX}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"	\
		CXXFLAGS="${CXXFLAGS} -I${PREFIX}/include"	\
		LDFLAGS="${LDFLAGS} -L${PREFIX}/lib"

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}
post-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/gps.conf ${PREFIX}/etc/gps.conf-dist
.for f in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${_DISTDIR}/${f} ${PREFIX}/libexec
.endfor
	@${PAGER} pkg-message

.include <bsd.port.mk>
