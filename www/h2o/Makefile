PORTNAME=	h2o
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.6
PORTREVISION=	2
CATEGORIES=	www

PATCH_SITES=	https://github.com/h2o/h2o/pull/:github
PATCHFILES=	3293.patch:-p1:github

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Optimized HTTP/2 server including support for TLS 1.3 and HTTP/1.x
WWW=		https://github.com/h2o/h2o

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

DEPRECATED=	Upstream EOL confirmed on 2023-10-10, removal planned for 2023-12-30
BROKEN_armv6=	fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported
BROKEN_armv7=	fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:noninja compiler:c11 cpe perl5 pkgconfig shebangfix ssl
CPE_VENDOR=	dena
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	share/h2o/start_server

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DWITH_BUNDLED_SSL=OFF

CONFLICTS=	h2o-devel

SUB_FILES=	${PORTNAME} ${PORTNAME}.conf.sample
SUB_LIST+=	H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR} \
		H2O_USER=${H2O_USER}

PLIST_SUB=	H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR} \
		H2O_USER=${H2O_USER}

PORTDOCS=	README.md

H2O_USER?=	www
H2O_GROUP?=	www

H2O_LOGDIR=	/var/log/${PORTNAME}/

OPTIONS_DEFINE=		DOCS MRUBY
OPTIONS_DEFAULT=	MRUBY
OPTIONS_SUB=		yes
MRUBY_DESC=		Build with embedded mruby handler support

MRUBY_USES=		bison ruby:build
MRUBY_CMAKE_BOOL=	WITH_MRUBY

post-patch:
	@${REINPLACE_CMD} -e 's|exec perl|exec ${LOCALBASE}/bin/perl|' \
		${WRKSRC}/share/h2o/annotate-backtrace-symbols \
		${WRKSRC}/share/h2o/fastcgi-cgi \
		${WRKSRC}/share/h2o/fetch-ocsp-response \
		${WRKSRC}/share/h2o/kill-on-close \
		${WRKSRC}/share/h2o/setuidgid \
		${WRKSRC}/share/h2o/start_server

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
