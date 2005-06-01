# Ports collection Makefile for:	sudosh
# Date created:				10/28/2004
# Whom:					cy@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		sudosh
PORTVERSION=		1.6.3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		cy@FreeBSD.org
COMMENT=	A sudo shell

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo

USE_GZIP=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--bindir="${PREFIX}/bin"
CONFIGURE_ARGS+=	--program-transform-name=''
.if defined(SUDOSH_LOGDIR)
CONFIGURE_ARGS+=	--with-logdir="${SUDOSH_LOGDIR}"
.else
CONFIGURE_ARGS+=	--with-logdir=/var/log/sudosh
.endif
CONFIGURE_ENV=		LDFLAGS="-lutil"

MAN1=			sudosh.1
MAN8=			sudosh-replay.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
