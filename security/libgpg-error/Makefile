# New ports collection makefile for:	libgpg-error
# Date created:		2003-10-12
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libgpg-error
PORTVERSION=	0.5
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}${EXTRACT_SUFX}.sig

MAINTAINER=	sergei@kolobov.com
COMMENT=	Common error values for all GnuPG components

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

GPG=		${LOCALBASE}/bin/gpg
GPG_FLAGS=	--keyserver pgp.mit.edu --keyserver-options auto-key-retrieve

DOCS=		AUTHORS ChangeLog NEWS README

post-fetch:
.if exists(${GPG})
	@${ECHO_MSG} "===> Verifying GnuPG signature"
	@${GPG} --verify ${GPG_FLAGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig
.else
	@${ECHO_MSG} "===> GnuPG not installed. Signature can not be verified"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
