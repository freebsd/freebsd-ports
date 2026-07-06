PORTNAME=	libifconfig
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	https://github.com/MainKt/freebsd-ports/releases/download/libifconf/

MAINTAINER=	saheed@FreeBSD.org
COMMENT=	Library providing the functionality of ifconfig(8)
WWW=		https://cgit.freebsd.org/src/tree/lib/libifconfig

LICENSE=	BSD3CLAUSE

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

CFLAGS+=	-Wno-pointer-sign

WRKSRC=		${WRKDIR}/libifconfig

_LIBIFCONFIG_HASH=	454322c08b8a
_LIBIFCONFIG_REV=	0

PLIST_FILES=	include/libifconfig.h \
		include/libifconfig_sfp.h \
		include/libifconfig_sfp_tables.h \
		lib/libifconfig.so \
		lib/libifconfig.so.2

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/tools/lua/template.lua)
IGNORE+=	requires FreeBSD sources (or set SRC_BASE)
.endif

.if ${OSVERSION} >= 1600000 && ${OSVERSION} < 1700000
DISTFILES=	libifconfig-${_LIBIFCONFIG_HASH}.tar.gz
.else
DISTFILES=	libifconfig-${OSREL}_${_LIBIFCONFIG_REV}.tar.gz
.endif

post-patch:
	   ${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libifconfig.so.2 ${STAGEDIR}${PREFIX}/lib
	${LN} -s libifconfig.so.2 ${STAGEDIR}${PREFIX}/lib/libifconfig.so
.for h in libifconfig.h libifconfig_sfp.h libifconfig_sfp_tables.h
	${INSTALL_DATA} ${WRKSRC}/${h} ${STAGEDIR}${PREFIX}/include
.endfor

_ALL_VERSIONS=	14.4 15.0 15.1
.if make(makesum)
DISTFILES=	libifconfig-${_LIBIFCONFIG_HASH}.tar.gz
.for version in ${_ALL_VERSIONS}
DISTFILES+=	libifconfig-${version}_${_LIBIFCONFIG_REV}.tar.gz
.endfor
.endif

.if defined(MAINTAINER_MODE)
_upload_dist:
	for version in ${_ALL_VERSIONS}; \
	do \
		cd /usr/src/lib && \
		git archive --format=tar.gz \
		    --output=libifconfig-$${version}_${_LIBIFCONFIG_REV}.tar.gz \
		    freebsd/releng/$${version} libifconfig ; \
	done
	cd /usr/src/lib && \
	git archive --format=tar.gz \
	    --output=libifconfig-${_LIBIFCONFIG_HASH}.tar.gz \
	    ${_LIBIFCONFIG_HASH} libifconfig ;
.endif

.include <bsd.port.post.mk>
