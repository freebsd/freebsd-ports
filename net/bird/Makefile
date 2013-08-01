# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
PORTVERSION=	1.3.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/ \
		http://bird.mpls.in/distfiles/bird/

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv4 version)

LICENSE=	GPLv2

USES=		bison
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_CSTD=	gnu89

OPTIONS_DEFINE=	FIREWALL AGG
FIREWALL_DESC=	Enable firewall protocol
AGG_DESC=	Enable aggregation protocol (EXPERIMENTAL)
NO_OPTIONS_SORT=	yes

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFIREWALL}
EXTRA_PATCHES+=	${FILESDIR}/firewall_support.patch
.endif

.if ${PORT_OPTIONS:MAGG}
EXTRA_PATCHES+=	${FILESDIR}/agg_support.patch
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/bird.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird.conf.example ${PREFIX}/etc/bird.conf ; \
		${CHMOD} 0640 ${PREFIX}/etc/bird.conf ; \
	fi

.include <bsd.port.post.mk>
