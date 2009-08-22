# New ports collection makefile for:	postfix-gps
# Date created:				2 September 2004
# Whom:					Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	1.005
PORTREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	SF/greylist/greylist/${PORTVERSION}-bugfix
PKGNAMEPREFIX=	postfix-
DISTNAME=	gps-${PORTVERSION}-bugfix

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Greylist Policy Service for postfix

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi
RUN_DEPENDS=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

SCRIPT_FILES=	gps-maintain.pl gps-db-update.pl
PLIST_FILES=	etc/gps.conf-dist libexec/gps libexec/gps-maintain.pl libexec/gps-db-update.pl
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/release-${PORTVERSION}

USE_AUTOTOOLS=	automake:19 autoconf:262
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec --includedir=${PREFIX}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"	\
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/gps.conf ${PREFIX}/etc/gps.conf-dist
.for f in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/libexec
.endfor
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
