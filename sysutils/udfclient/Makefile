# New ports collection makefile for:   udfclient
# Date created:        3 January 2005
# Whom:                Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	udfclient
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.13thmonkey.org/udfclient/releases/
DISTNAME=	UDFclient.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Tools for UDF filesystem

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	with_pthread_cflags="${PTHREAD_CFLAGS}" \
		with_thread_libs="${PTHREAD_LIBS}"
MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/udfdump \
		bin/udfclient \
		bin/newfs_udf \
		bin/cd_sessions \
		bin/cd_disect \
		bin/cdrw_format

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.include <bsd.port.post.mk>
