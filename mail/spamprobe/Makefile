# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#

PORTNAME=	spamprobe
PORTVERSION=	0.8b
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mdodd@freebsd.org
COMMENT=	Spam detector using Bayesian analysis of word counts

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	FILESDIR="${FILESDIR}"

.include <bsd.port.pre.mk>

post-build:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} -f \
		${FILESDIR}/Makefile.export0_6 clean all

post-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} -f \
		${FILESDIR}/Makefile.export0_6 install
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
