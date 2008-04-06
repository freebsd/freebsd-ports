# Ports collection makefile for:	gem-syntax
# Date created:				11 Sep 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	syntax
PORTVERSION=	1.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A module for using Systax highlighting in Ruby

USE_RUBY=	yes

.include <bsd.port.pre.mk>
#.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
# syntax.gem has invalid content, we need to buuild the gem ourself

.if ${RUBY_VER} == 1.8
BUILD_DEPENDS+=	${RUBYGEMBIN}:${PORTSDIR}/devel/ruby-gems
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

REV=		${RUBY_VER}
GEMS_BASE_DIR=	lib/ruby/gems/${REV}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
SPEC_DIR=	${GEMS_BASE_DIR}/specifications
GEM_NAME?=	${PORTNAME}-${PORTVERSION}
GEM_LIB_DIR=	${GEMS_DIR}/${GEM_NAME}
GEM_DOC_DIR=	${DOC_DIR}/${GEM_NAME}
GEM_SPEC=	${SPEC_DIR}/${GEM_NAME}.gemspec
GEM_CACHE=	${CACHE_DIR}/${GEM_NAME}.gem

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		REV="${REV}" \
		GEMS_BASE_DIR="lib/ruby/gems/${REV}" \
		GEMS_DIR="${GEMS_BASE_DIR}/gems" \
		DOC_DIR="${GEMS_BASE_DIR}/doc" \
		CACHE_DIR="${GEMS_BASE_DIR}/cache" \
		SPEC_DIR="${GEMS_BASE_DIR}/specifications" \
		PORT="${PORTNAME}-${PORTVERSION}" \
		GEM_NAME="${GEM_NAME}" \
		GEM_LIB_DIR="${GEM_LIB_DIR}" \
		GEM_DOC_DIR="${GEM_DOC_DIR}" \
		GEM_SPEC="${GEM_SPEC}" \
		GEM_CACHE="${GEM_CACHE}" \
		EXTRACT_SUFX="${EXTRACT_SUFX}"

RUBYGEMBIN=	${LOCALBASE}/bin/gem${RUBY_VER:S/.//}

do-build:
	cd ${WRKSRC} && ${RUBYGEMBIN} build syntax.gemspec

do-install:
	${RUBYGEMBIN} install --install-dir ${PREFIX}/lib/ruby/gems/${REV} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.gem

.include <bsd.port.post.mk>
