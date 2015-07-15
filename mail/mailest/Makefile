# $FreeBSD$

PORTNAME=	mailest
PORTVERSION=	0.9.20
CATEGORIES=	mail

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Hyper Estraier backend for Mew

LICENSE=	BSD2CLAUSE ISCL LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.BSD2CLAUSE
LICENSE_FILE_ISCL=	${WRKSRC}/LICENSE.ISCL
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.LGPL21

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2 \
		libqdbm.so:${PORTSDIR}/databases/qdbm \
		libestraier.so:${PORTSDIR}/textproc/hyperestraier
RUN_DEPENDS=	mewl:${PORTSDIR}/mail/mew

USES=		iconv
USE_EMACS=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	yasuoka
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
MAKE_ENV=	USE_BSDMAKE=true WITH_INSTALL_AS_USER=true

post-extract:
	${SED} "/\*-/,/*\//!d" ${WRKSRC}/bytebuf.c > ${LICENSE_FILE_BSD2CLAUSE}
	${SED} "/^\/\*/,/ *\//!d" ${WRKSRC}/mailestctl.c > ${LICENSE_FILE_ISCL}
	${SED} "/^\/\*\*/,/\*\*\//!d" ${WRKSRC}/estdraft.c \
	    > ${LICENSE_FILE_LGPL21}

.include <bsd.port.mk>
