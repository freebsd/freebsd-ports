# New ports collection makefile for:	wmbiff
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		wmbiff
PORTVERSION=		0.4.20
CATEGORIES=		mail windowmaker afterstep
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		simon@FreeBSD.org
COMMENT=		An xbiff-like Window Maker dock app

USE_X_PREFIX=		yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgnutls.so.12)
WITH_GNUTLS=		yes
.endif

.ifdef WITH_GNUTLS
LIB_DEPENDS+=		gcrypt.12:${PORTSDIR}/security/libgcrypt \
			gnutls.12:${PORTSDIR}/security/gnutls
.endif

USE_XPM=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=			wmbiff.1
MAN5=			wmbiffrc.5

post-install:
	@${ECHO_MSG} "===>   Installing sample.wmbiffrc to ${DATADIR}"
	@${ECHO_MSG} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${INSTALL_DATA} -m 644 ${WRKSRC}/wmbiff/sample.wmbiffrc ${DATADIR}

.include <bsd.port.post.mk>
