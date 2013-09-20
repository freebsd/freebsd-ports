# Created by: Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
# $FreeBSD$

PORTNAME=	pari
PORTVERSION=	2.3.5
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/OLD/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Mathematics library and advanced calculator package

LICENSE=	GPLv2

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	gp
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--share-prefix=${PREFIX}/share \
		--with-gmp=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		gp.1 gp-${GP_VERSION}.1 gphelp.1 tex2mail.1
MLINKS=		gp.1 pari.1
PORTDOCS=	*
PLIST_SUB=	GP_VERSION=${GP_VERSION} PORTVERSION=${PORTVERSION}

GP_VERSION=	${PORTVERSION:R}

NO_STAGE=	yes
post-install:
	@if [ -L ${MAN1PREFIX}/man/man1/pari.1 ]; then \
		${RM} -f ${MAN1PREFIX}/man/man1/pari.1 ;\
	fi

.include <bsd.port.mk>
