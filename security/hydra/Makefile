# ex:ts=8
# Ports collection makefile for:  hydra
# Date created:			  Tue Oct 08, 2002
# Whom:				  Laurent LEVIER (llevier@argosnet.com)
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	2.2
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	groups/thc

MAINTAINER=	llevier@argosnet.com
COMMENT=	Bruce Force Attack Utility working on multiple network services

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.if !target(post-install) && (${PORTNAME} == "hydra")
post-install:
	@${STRIP_CMD} ${PREFIX}/bin/hydra
.endif

.include <bsd.port.post.mk>
