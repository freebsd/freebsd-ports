# New ports collection makefile for:  	bbmail
# Date created:		May 3 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bbmail
PORTVERSION=	0.8.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbtools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool intended for Blackbox that checks for new mail

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		bbmail.1
PLIST_FILES=	bin/bbmail share/bbtools/bbmail.bb

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
