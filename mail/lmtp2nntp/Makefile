# New ports collection makefile for:	lmtp2nntp
# Date created:				12 November 2001
# Whom:	      				Thomas Lotterer <thomas.lotterer@cw.com>
#
# $FreeBSD$
#

PORTNAME=	lmtp2nntp
PORTVERSION=	1.3.0
CATEGORIES=	mail news
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	tool/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OSSP mail to news gateway

LIB_DEPENDS=	str.9:${PORTSDIR}/devel/str \
		ex.10:${PORTSDIR}/devel/ossp-ex \
		sa.12:${PORTSDIR}/net/ossp-sa \
		var.11:${PORTSDIR}/devel/ossp-var

MAN8=		lmtp2nntp.8
PLIST_FILES=	sbin/lmtp2nntp
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex="${LOCALBASE}" --with-str="${LOCALBASE}" \
		--with-sa="${LOCALBASE}" --with-var="${LOCALBASE}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.include <bsd.port.post.mk>
