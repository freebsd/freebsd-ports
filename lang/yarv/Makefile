# New ports collection makefile for:	yarv
# Date created:				24 Jul 2006
# Whom:					Jun Mukai aka jmuk <mukai@jmuk.org>
#
# $FreeBSD$
#

PORTNAME=	yarv
PORTVERSION=	0.4.1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.atdot.net/yarv/
DIST_SUBDIR=	ruby

MAINTAINER=	mukai@jmuk.org
COMMENT=	Yet Another Ruby Virtual-machine

USE_GCC=	4.0+
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_RUBY=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} --program-suffix=20 \
		--enable-shared --with-openssl-include=${OPENSSLINC}
CONFIGURE_ARGS+=--enable-ipv6
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"

OPTIONS=	DEBUG "Enable debugging information" off \
		THREADS "Enable threading support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		does not build
.endif

.if ${OSVERSION} < 600000
BROKEN=		Does not build on 5.x
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-nodoc
PLIST_SUB+=	PORTSDOCS="@comment "
.else
INSTALL_TARGET=	install
PLIST_SUB+=	PORTSDOCS=""
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-g
STRIP=		# none
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=--enable-pthread
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}+pthreads
.else
CONFIGURE_ARGS+=--disable-pthread
.endif

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include <bsd.port.post.mk>
