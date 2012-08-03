# New ports collection makefile for:	qadsl
# Date created:				13 December 2001
# Whom:					Arne Lundberg <arlu@telia.com>
#
# $FreeBSD$
#

PORTNAME=	qadsl
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/alive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto login/Keep-alive for Telia AB ADSL, COMHEM Cable, and Tiscali Internet

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RC_SUBR=	qadsl.sh
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-global-cfg=${PREFIX}/etc/qadsl.conf \
		--with-pidfile=/var/run/qadsl.pid
MAKE_JOBS_SAFE=	yes

MAN8=		qadsl.8
MAN5=		qadsl.conf.5
INFO=		qadsl
PLIST_FILES=	sbin/qadsl etc/qadsl.conf.sample

post-extract:
	@${CP} ${WRKSRC}/etc/qadsl.conf ${WRKSRC}/etc/qadsl.conf.sample

post-patch:
	@${REINPLACE_CMD} -e \
		'/echo $${CFLAGS}/s|^|#| ; \
		 /echo $${CXXFLAGS}/s|^|#| ; \
		 s|$$OPTIMIZER_CFLAGS||' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
