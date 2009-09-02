# New ports collection makefile for:    libtnl
# Date created:         26 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtnl
PORTVERSION=	1.5.0
CATEGORIES=	net devel
MASTER_SITES=	SF/opentnl/TNL%20Source/${PORTVERSION}
DISTNAME=	tnl-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A robust, secure, easy to use cross-platform C++ networking API

WRKSRC=		${WRKDIR}/tnl/tnl
USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`
# Other arches can be added easily, provided there is hardware to test:
ONLY_FOR_ARCHS=	i386 amd64
.if defined(NO_PROFILE) || defined(NOPROFILE)
PLIST_SUB+=	PROFILE='@comment '
.else
PLIST_SUB+=	PROFILE=''
.endif

# When security/libtomcrypt is fixed to provide a shared version, we'll
# stop extracting our own and will LIB_DEPEND on theirs instead:
#LIB_DEPENDS=	tomcrypt:${PORTSDIR}/security/libtomcrypt
#
#EXTRACT_AFTER_ARGS=|${TAR} -xpf - --exclude tnl/libtomcrypt

pre-su-install:
	${MKDIR} ${PREFIX}/include/tnl

.include <bsd.port.mk>
