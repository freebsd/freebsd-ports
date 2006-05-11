# New ports collection makefile for: apollon
# Date Created:			29 Dec 2004
# Whom:				Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	apollon
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	apollon

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	KDE client for giFT daemon

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-patch:
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/^(all:)[[:space:]]+docs-am/\1/; s/^(SUBDIRS.+)doc/\1/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
