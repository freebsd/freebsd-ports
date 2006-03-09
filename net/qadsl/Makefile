# New ports collection makefile for:	qadsl
# Date created:				13 December 2001
# Whom:					Arne Lundberg <arlu@telia.com>
#
# $FreeBSD$
#

PORTNAME=	qadsl
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.gnu.org/releases/alive/
DISTNAME=	qadsl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto login/Keep-alive for Telia AB ADSL, COMHEM Cable and Tiscali Internet

USE_RC_SUBR=	qadsl.sh
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-global-cfg=${PREFIX}/etc/qadsl.conf \
		--with-pidfile=/var/run/qadsl.pid

MAN8=		qadsl.8
MAN5=		qadsl.conf.5
INFO=		qadsl
PLIST_FILES=	sbin/qadsl etc/qadsl.conf.sample

post-extract:
	@${CP} ${WRKSRC}/etc/qadsl.conf ${WRKSRC}/etc/qadsl.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
