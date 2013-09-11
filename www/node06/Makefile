# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	node
PORTVERSION=	0.6.21
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

DEPRECATED=	Unsupported upstream, not compatible with current
EXPIRATION_DATE=	2013-10-11

OPTIONS_DEFINE=	SHARED_V8
SHARED_V8_DESC=	Build with lang/v8

CONFLICTS=	node-0.[0-57-9]* node-devel-0.[0-9]*

LATEST_LINK=	node06

CONFIGURE_ARGS=	--no-ssl2 \
		--openssl-includes=${OPENSSLINC} \
		--openssl-libpath=${OPENSSLLIB} \
		--prefix=${PREFIX:S/^${DESTDIR}//} \
		--without-npm
HAS_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2.7
USE_OPENSSL=	yes

MAN1=		node.1

WAF_ARGS=	--jobs=${MAKE_JOBS_NUMBER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED_V8}
CONFIGURE_ARGS+=--shared-v8 \
		--shared-v8-includes=${LOCALBASE}/include \
		--shared-v8-libpath=${LOCALBASE}/lib \
		--without-snapshot
LIB_DEPENDS+=	v8:${PORTSDIR}/lang/v8
PLIST_SUB+=	SHARED_V8="@comment "
.else
PLIST_SUB+=	SHARED_V8=""
.endif

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tools/waf-light ${WAF_ARGS} build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tools/waf-light ${WAF_ARGS} install)

post-install:
	${MKDIR} ${PREFIX}/lib/node_modules/
	${TOUCH} ${PREFIX}/lib/node_modules/.keepme
	${INSTALL_MAN} ${WRKSRC}/doc/node.1 ${MANPREFIX}/man/man1/
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: If you need npm (Node Package Manager), please install www/npm."
	@${ECHO_MSG}

.include <bsd.port.mk>
