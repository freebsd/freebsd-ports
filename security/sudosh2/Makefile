# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=		sudosh2
PORTVERSION=		1.0.4
CATEGORIES=		security
MASTER_SITES=		SF/${PORTNAME}
EXTRACT_SUFX=		.tbz2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Second version of the sudo shell
CONFLICTS=		sudosh-*

USE_BZIP2=		yes
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
.include <bsd.port.pre.mk>

post-install:
	@${TEST} -f ${PREFIX}/etc/sudosh.conf || ${CP} -p ${PREFIX}/etc/sudosh.conf.sample ${PREFIX}/etc/sudosh.conf

.include <bsd.port.post.mk>
