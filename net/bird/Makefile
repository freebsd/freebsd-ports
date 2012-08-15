# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird
PORTVERSION=	1.3.8
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv4 version)

LICENSE=	GPLv2

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

OPTIONS=	FIBS		"Enable multiple fib support" Off \
		FIREWALL	"Enable firewall protocol" Off \
		AGG		"Enable aggregation protocol (EXPERIMENTAL)" Off

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

.include <bsd.port.pre.mk>

.if defined(WITH_FIBS)
EXTRA_PATCHES+=	${FILESDIR}/fibs.diff
.endif

.if defined(WITH_FIREWALL)
EXTRA_PATCHES+=	${FILESDIR}/firewall_support.patch
.endif

.if defined(WITH_AGG)
EXTRA_PATCHES+=	${FILESDIR}/agg_support.patch
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/bird.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird.conf.example ${PREFIX}/etc/bird.conf ; \
		${CHMOD} 0640 ${PREFIX}/etc/bird.conf ; \
	fi
.if defined(WITH_FIBS)
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
