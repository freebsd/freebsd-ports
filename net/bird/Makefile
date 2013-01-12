# Created by:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	bird
PORTVERSION=	1.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/ \
		http://bird.mpls.in/distfiles/bird/

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv4 version)

LICENSE=	GPLv2

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

OPTIONS_DEFINE=	FIBS FIREWALL AGG
FIBS_DESC=	Enable multiple fib support
FIREWALL_DESC=	Enable firewall protocol
AGG_DESC=	Enable aggregation protocol (EXPERIMENTAL)
NO_OPTIONS_SORT=	yes

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFIBS}
EXTRA_PATCHES+=	${FILESDIR}/fibs.diff
.endif

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
.if ${PORT_OPTIONS:MFIBS}
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}
	@${ECHO_MSG} "        WARNING: Please take a look on kern/134931"
	@${ECHO_MSG} "        WARNING: before using multiple fibs in production!"
	@${ECHO_MSG} "        This PR was fixed in r225975(8.2-S) on Oct 4, 2011"
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
