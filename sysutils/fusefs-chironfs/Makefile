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

RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

PLIST_FILES=	bin/chironfs bin/chirctl
PORTDOCS=	*
MAN8=		chironfs.8

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, doc , ,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from sysutils/fusefs-kmod
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
