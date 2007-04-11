# New ports collection makefile for:	fusefs-funionfs
# Date created:		2006-07-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	funionfs
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://funionfs.apiou.org/file/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Union filesystem for the FUSE driver

BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
GNU_CONFIGURE=	yes

MAN1=		funionfs.1
PLIST_FILES=	bin/funionfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from fusefs-kmod
IGNORE=		requires FreeBSD 6.x or above
.endif

.include <bsd.port.post.mk>
