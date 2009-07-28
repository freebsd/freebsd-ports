# Ports collection makefile for:  source-highlight
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	source-highlight
PORTVERSION=	2.11.1
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS="${NOPORTDOCS}"
.endif

USE_GMAKE=	yes

MAN1=	source-highlight.1 check-regexp.1
INFO=	source-highlight

OPTIONS=	BASH	"Support Bash completion"	Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if defined(WITH_BASH)
RUN_DEPENDS+=	${LOCALBASE}/etc/bash_completion:${PORTSDIR}/shells/bash-completion
CONFIGURE_ARGS+=	--with-bash-completion
PLIST_SUB+=	BASH=""
.else
CONFIGURE_ARGS+=	--without-bash-completion
PLIST_SUB+=	BASH="@comment "
.endif

.include <bsd.port.post.mk>
