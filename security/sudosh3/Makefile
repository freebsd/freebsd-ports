# Ports collection Makefile for:	sudosh
# Date created:				10/28/2004
# Whom:					cy@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		sudosh3
PORTVERSION=		3.2.0
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		SF/${PORTNAME}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Third version of the sudo shell
CONFLICTS=		sudosh-*

FORBIDDEN=		Secunia Advisory SA38292, ISS X-Force sudosh-replay-bo (55903), replay() function buffer overflow.

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

.include <bsd.port.pre.mk>

post-install:
	@${TEST} -f ${PREFIX}/etc/sudosh.conf || ${CP} -p ${PREFIX}/etc/sudosh.conf.sample ${PREFIX}/etc/sudosh.conf

.include <bsd.port.post.mk>
