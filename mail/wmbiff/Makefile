# New ports collection makefile for:	wmbiff
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		wmbiff
PORTVERSION=		0.4.7
CATEGORIES=		mail windowmaker afterstep
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jim@FreeBSD.org

USE_X_PREFIX=		yes
USE_XPM=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=			wmbiff.1
MAN5=			wmbiffrc.5

post-install:
	@${ECHO_MSG} "===>   Installing sample.wmbiffrc to ${DATADIR}"
	@${ECHO_MSG} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${INSTALL_DATA} -m 644 ${WRKSRC}/wmbiff/sample.wmbiffrc ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
