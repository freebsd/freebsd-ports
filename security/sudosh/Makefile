# Ports collection Makefile for:	sudosh
# Date created:				10/28/2004
# Whom:					cy@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		sudosh
PORTVERSION=		1.8.2
PORTREVISION=		5
CATEGORIES=		security
MASTER_SITES=		SF/${PORTNAME}/OldFiles
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		A sudo shell

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo

GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--bindir="${PREFIX}/bin"
CONFIGURE_ARGS+=	--sysconfdir="${PREFIX}/etc"
CONFIGURE_ARGS+=	--program-transform-name=''
.if defined(SUDOSH_LOGDIR)
CONFIGURE_ARGS+=	--with-logdir="${SUDOSH_LOGDIR}"
.else
CONFIGURE_ARGS+=	--with-logdir=/var/log/sudosh
.endif
CONFIGURE_ENV=		LDFLAGS="-lutil"

MAN1=			sudosh.1
MAN5=			sudosh.conf.5
MAN8=			sudosh-replay.8

.include <bsd.port.mk>
