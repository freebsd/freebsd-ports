# ex:ts=8
# New ports collection makefile for:	botan
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	botan
PORTVERSION=	1.4.4
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/files/
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A portable, easy to use, and efficient C++ crypto library

USE_BZIP2=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	--prefix=${PREFIX} gcc-freebsd-generic
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}" \
		LANG_FLAGS="-fpermissive"
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/Botan-${PORTVERSION}
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
CONFIGURE_ARGS+=	--noauto
PLIST_SUB+=	OS_4="@comment "
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include::mem_pool.h-gcc295
PLIST_SUB+=	OS_4=""
post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
.endif

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
