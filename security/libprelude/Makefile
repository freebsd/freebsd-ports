# New ports collection makefile for:	libprelude
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System librairies

USE_REINPLACE=		yes
USE_GMAKE=		yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc --localstatedir=/var

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=		YES
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

post-extract:
	@${ECHO} ""
	@${ECHO} "*------------------------------------------------------------------*"
	@${ECHO} "Options:"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL=yes         Disable SSL support in libprelude"
	@${ECHO} "*------------------------------------------------------------------*"
	@${ECHO} ""

.include <bsd.port.mk>
