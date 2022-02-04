PORTNAME=	fts-xapian
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://github.com/grosjo/fts-xapian/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	dovecot-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Dovecot FTS plugin based on Xapian

LICENSE=	LGPL21

BUILD_DEPENDS=	dovecot>=2.3.7:mail/dovecot
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libxapian.so:databases/xapian-core
RUN_DEPENDS=	dovecot>=2.3.7:mail/dovecot

USES=		autoreconf compiler:c++11-lang libtool pkgconfig

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	lib/dovecot/lib21_fts_xapian_plugin.a \
		lib/dovecot/lib21_fts_xapian_plugin.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dovecot/lib21_fts_xapian_plugin.so

.include <bsd.port.mk>
