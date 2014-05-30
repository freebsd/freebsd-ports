# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=		sudosh
PORTVERSION=		1.8.2
PORTREVISION=		5
CATEGORIES=		security
MASTER_SITES=		SF/${PORTNAME}/OldFiles

MAINTAINER=		cy@FreeBSD.org
COMMENT=		A sudo shell

DEPRECATED=		Funcition replaced by sudo -s
EXPIRATION_DATE=	2014-07-01

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
LDFLAGS+=		-lutil

MAN1=			sudosh.1
MAN5=			sudosh.conf.5
MAN8=			sudosh-replay.8

NO_STAGE=	yes
.include <bsd.port.mk>
