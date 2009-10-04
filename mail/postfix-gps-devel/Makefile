# New ports collection makefile for:	postfix-gps-devel
# Date created:				29 May 2005
# Whom:					Dennis K. Jensen <freebsd@signout.dk>
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	1.004
PORTREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	http://mimo.gn.apc.org/gps/
PKGNAMEPREFIX=	postfix-
PKGNAMESUFFIX=	-devel
DISTNAME=	gps-${PORTVERSION}

MAINTAINER=	freebsd@signout.dk
COMMENT=	Greylist Policy Service for postfix

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi
RUN_DEPENDS=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers

DEPRECATED=	Older than main port, no sign of maintainer activity beyond port creation 4+ years ago
EXPIRATION_DATE=2009-11-03

SCRIPT_FILES=	gps-maintain.pl gps-db-update.pl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	automake:19 autoconf:262
USE_GCC=	3.4
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec --includedir=${PREFIX}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"	\
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}
post-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/gps.conf ${PREFIX}/etc/gps.conf-dist
.for f in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/libexec
.endfor
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${PKGMESSAGE}

.include <bsd.port.mk>
