# New ports collection makefile for:	xrdp
# Date created:				2007-02-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	xrdp
PORTVERSION=	0.5.0.20090811cvs
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/pav

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Remote Desktop Protocol (RDP) server

USE_AUTOTOOLS=	autoconf:268:env automake:111:env libtool:22
GNU_CONFIGURE=	yes
USE_RC_SUBR=	xrdp

CONFIGURE_ARGS=	--localstatedir=/var

.if defined(WITH_DEBUG)
CFLAGS+=	-DXRDP_DEBUG
.endif

MAN5=		sesman.ini.5 xrdp.ini.5
MAN8=		xrdp-sesman.8 xrdp-sesrun.8 xrdp.8

SUB_FILES=	pkg-message

post-patch:
.for f in sesman/sesman.ini sesman/startwm.sh xrdp/rsakeys.ini xrdp/xrdp.ini
	@${MV} ${WRKSRC}/$f ${WRKSRC}/$f.sample
.endfor

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-install:
.for f in rsakeys.ini sesman.ini startwm.sh xrdp.ini
	@if [ ! -f ${PREFIX}/etc/xrdp/$f ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/$f.sample ${PREFIX}/etc/xrdp/$f ; \
	fi
.endfor
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
