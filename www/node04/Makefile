# New ports collection makefile for:		node
# Date created:					2010-04-12
# Whom:						Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	node
PORTVERSION=	0.4.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

MAN1=		node.1

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	pkgconfig

CONFLICTS=	node-0.[0-35-9]* node-devel-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST}
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
LIB_DEPENDS+=	v8.1:${PORTSDIR}/lang/v8
CONFIGURE_ARGS+=	--shared-v8-includes=${LOCALBASE}/include --shared-v8-libpath=${LOCALBASE}/lib
PLIST_SUB+=	SHAREDV8="@comment "
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src__node_buffer.cc
.else
PLIST_SUB+=	SHAREDV8=""
.endif

.if !defined(DISABLE_MAKE_JOBS)
WAF_ARGS=	--jobs=${MAKE_JOBS_NUMBER}
.endif

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tools/waf-light ${WAF_ARGS} build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tools/waf-light ${WAF_ARGS} install)

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/node.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
