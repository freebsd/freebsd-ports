# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#

PORTNAME=	spamprobe
PORTVERSION=	0.7a
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

MAINTAINER=	mdodd@freebsd.org

MAKEFILE=	${FILESDIR}/Makefile

.include <bsd.port.pre.mk>

post-build:
	@cd ${WRKSRC} && ${MAKE} -f ${FILESDIR}/Makefile.export0_6 clean
	@cd ${WRKSRC} && ${MAKE} -f ${FILESDIR}/Makefile.export0_6

post-extract:
	@${CP} ${FILESDIR}/spamprobe.1 ${WRKSRC}/

post-install:
	@cd ${WRKSRC} && ${MAKE} -f ${FILESDIR}/Makefile.export0_6 install
	@${CAT} ${FILESDIR}/post-install-notes

.include <bsd.port.post.mk>
