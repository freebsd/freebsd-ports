# New ports collection makefile for:	fusefs-ntfs
# Date created: 			25 July 2006
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	ntfs
PORTVERSION=	2009.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ntfs-3g.org/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Mount NTFS partitions (read/write) and disk images

BUILD_DEPENDS=	fusefs-libs>=2.7.2:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	LOCK "Lock the device when mounting (avoids access)" on \
		UBLIO "Enable user space cache for improved speed" on

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/ntfs-3g

MAN8=		ntfs-3g.8 ntfs-3g.probe.8
MLINKS=		ntfs-3g.8 mount_ntfs-3g.8

.include <bsd.port.pre.mk>

.if defined(WITH_LOCK)
CFLAGS+=	-DUSE_LOCK
.endif

.if defined(WITH_UBLIO)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ublio
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CFLAGS+=	-DUSE_UBLIO
.endif

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -Ee 's|^(install-data-am:) .*|\1|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
