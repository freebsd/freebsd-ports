# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	0.4.7
CATEGORIES=	security
MASTER_SITES= 	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/aegypten
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sig

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"KSBA is an X.509 Library"

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOCONF_VER=	253
USE_PERL5_BUILD=	yes

INFO=	ksba

.include <bsd.port.pre.mk>

pre-extract:
.if exists(${PREFIX}/bin/gpg)
	@${ECHO_CMD} "===> Verifying GnuPG Signature."
	-${PREFIX}/bin/gpg --keyserver pgp.mit.edu --recv-key 57548DCD
	cd ${DISTDIR}; ${PREFIX}/bin/gpg --verify \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sig \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.else
	@${ECHO_CMD} "===> GnuPG not installed. Signature can not be verified"
.endif

.include <bsd.port.post.mk>
