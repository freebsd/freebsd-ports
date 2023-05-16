PORTNAME=	magicfilter
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.i
CATEGORIES=	print

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Customizable, extensible automatic printer filter
WWW=		https://www.pell.portland.or.us/~orc/Code/magicfilter/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmagic.so:sysutils/file
RUN_DEPENDS=	${LOCALBASE}/lib/libmagic.so:sysutils/file

USES=		ghostscript
USE_GITHUB=	yes
GH_ACCOUNT=	Orc

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--confdir=${PREFIX}/etc \
			--filterdir=${PREFIX}/libexec/magicfilter \
			--use-fifo
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
