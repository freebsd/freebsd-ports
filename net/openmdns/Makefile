# $FreeBSD$

PORTNAME=	openmdns
DISTVERSION=	0.7-10
DISTVERSIONSUFFIX=	-gb1c3540
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multicast DNS and Service Discovery daemon

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	haesbaert
GH_PROJECT=	mdnsd

CONFLICTS_INSTALL=	mDNSResponder # sbin/mdnsd

USES=		localbase uidfix
USE_RC_SUBR=	mdnsd
USE_LDCONFIG=	yes
# Add SHLIB_MAJOR=0 and drop @comment if the library is desired
MAKE_ENV=	LDADD="${LIBS}" NO_PROFILE=1
MAKE_ARGS=	BINDIR="${PREFIX}/sbin" \
		LIBDIR="${PREFIX}/lib" \
		MANDIR="${PREFIX}/share/man/man"
CFLAGS+=	-D__dead=__dead2
LDFLAGS+=	-Wl,--as-needed # -lutil
LIBS+=		-lmdns -lopenbsd
SUB_LIST=	COMMENT="${COMMENT}"
PLIST_FILES=	sbin/mdnsctl \
		sbin/mdnsd \
		"@comment lib/libmdns.a" \
		share/man/man8/mdnsctl.8.gz \
		share/man/man8/mdnsd.8.gz
PORTDOCS=	*

USERS=		_mdnsd
GROUPS=		_mdnsd

OPTIONS_DEFINE=	DOCS STATIC

STATIC_BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:devel/libevent \
			${LOCALBASE}/lib/libopenbsd.a:devel/libopenbsd
STATIC_MAKE_ENV=	NO_SHARED=1
STATIC_LIB_DEPENDS_OFF=	libevent.so:devel/libevent \
			libopenbsd.so:devel/libopenbsd

post-patch:
# warning: duplicate script for target "maninstall" ignored
	@${REINPLACE_CMD} '/bsd\.man\.mk/d' ${WRKSRC}/*/Makefile

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
