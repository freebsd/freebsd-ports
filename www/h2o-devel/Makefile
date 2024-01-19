PORTNAME=	h2o
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0-dev.20231107
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Optimized HTTP/2 server including support for TLS 1.3 and HTTP/1.x
WWW=		https://github.com/h2o/h2o

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

BROKEN_armv6=	fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported
BROKEN_armv7=	fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:noninja compiler:c11 cpe perl5 pkgconfig shebangfix ssl
CPE_VENDOR=	dena
USE_GITHUB=	yes
GH_TAGNAME=	b15937e

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	share/h2o/start_server

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=OFF

CONFLICTS=	h2o

SUB_FILES=	${PORTNAME} ${PORTNAME}.conf.sample
SUB_LIST+=	H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR} \
		H2O_USER=${H2O_USER}

PLIST_SUB=	H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR} \
		H2O_USER=${H2O_USER}
PORTDOCS=	README.md

.ifnmake portclippy
H2O_USER?=	www
H2O_GROUP?=	www

H2O_LOGDIR=	/var/log/${PORTNAME}/
.endif

OPTIONS_DEFINE=		DOCS MRUBY
OPTIONS_DEFAULT=	MRUBY
OPTIONS_SUB=		yes
MRUBY_DESC=		Build with embedded mruby handler support
MRUBY_USES=		bison ruby:build
MRUBY_CMAKE_BOOL=	WITH_MRUBY

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CMAKE_ARGS+=	-DWITH_FUSION=OFF
.endif

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
