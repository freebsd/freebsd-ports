# New ports collection makefile for:	fusefs-chironfs
# Date created:				2008-04-06
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chironfs
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A FUSE based filesystem with replication at the filesystem level

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_FUSE=	yes

PLIST_FILES=	bin/chironfs bin/chirctl
PORTDOCS=	*
MAN8=		chironfs.8

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, doc , ,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
