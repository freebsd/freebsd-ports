PORTNAME=	libtnl
PORTVERSION=	1.5.0
PORTREVISION=	8
CATEGORIES=	net devel
MASTER_SITES=	SF/opentnl/TNL%20Source/${PORTVERSION}
DISTNAME=	tnl-${PORTVERSION}-source

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Robust, secure, easy to use cross-platform C++ networking API
WWW=		https://sourceforge.net/projects/opentnl/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

# Other arches can be added easily, provided there is hardware to test:
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

USES=		uidfix
USE_GCC=	yes
USE_LDCONFIG=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd

WRKSRC=		${WRKDIR}/tnl/tnl

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || defined(NOPROFILE) || ( ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 )))
PLIST_SUB+=	PROFILE='@comment '
.else
PLIST_SUB+=	PROFILE=''
.endif

# When security/libtomcrypt is fixed to provide a shared version, we'll
# stop extracting our own and will LIB_DEPEND on theirs instead:
#LIB_DEPENDS=	tomcrypt:security/libtomcrypt
#
#EXTRACT_AFTER_ARGS=|${TAR} -xpf - --exclude tnl/libtomcrypt

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/tnl

.include <bsd.port.post.mk>
