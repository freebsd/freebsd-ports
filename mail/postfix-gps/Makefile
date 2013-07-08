# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	1.005
PORTREVISION=	4
CATEGORIES=	mail security
MASTER_SITES=	SF/greylist/greylist/${PORTVERSION}-bugfix
PKGNAMEPREFIX=	postfix-
DISTNAME=	gps-${PORTVERSION}-bugfix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Greylist Policy Service for postfix

LIB_DEPENDS=	dbi:${PORTSDIR}/databases/libdbi
RUN_DEPENDS=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

SCRIPT_FILES=	gps-maintain.pl gps-db-update.pl
PLIST_FILES=	etc/gps.conf-dist libexec/gps libexec/gps-maintain.pl libexec/gps-db-update.pl
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/release-${PORTVERSION}

USE_AUTOTOOLS=	automake autoconf
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec --includedir=${PREFIX}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include

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
