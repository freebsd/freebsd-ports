# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#

PORTNAME=	spamprobe
PORTVERSION=	0.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mdodd@freebsd.org

MAKEFILE=	${FILESDIR}/Makefile

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/spamprobe.1 ${WRKSRC}/

.include <bsd.port.post.mk>
