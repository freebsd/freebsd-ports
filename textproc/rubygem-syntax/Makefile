# Ports collection makefile for:	gem-syntax
# Date created:				11 Sep 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	syntax
PORTVERSION=	1.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/4953/
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A module for using Systax highlighting in Ruby

.include <bsd.port.pre.mk>
#.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
# syntax.gem has invalid content, we need to buuild the gem ourself

BUILD_DEPENDS+=	${RUBYGEMBIN}:${PORTSDIR}/devel/ruby-gems
RUN_DEPENDS+=	${BUILD_DEPENDS}

REV=		1.8
GEMS_BASE_DIR=	lib/ruby/gems/${REV}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
SPEC_DIR=	${GEMS_BASE_DIR}/specifications

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		REV="${REV}" \
		GEMS_BASE_DIR="lib/ruby/gems/${REV}" \
		GEMS_DIR="${GEMS_BASE_DIR}/gems" \
		DOC_DIR="${GEMS_BASE_DIR}/doc" \
		CACHE_DIR="${GEMS_BASE_DIR}/cache" \
		SPEC_DIR="${GEMS_BASE_DIR}/specifications" \
		PORT="${PORTNAME}-${PORTVERSION}"

RUBYGEMBIN=	${LOCALBASE}/bin/gem

do-build:
	cd ${WRKSRC} && ${RUBYGEMBIN} build syntax.gemspec

do-install:
	${RUBYGEMBIN} install --install-dir ${PREFIX}/lib/ruby/gems/${REV} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.gem

.include <bsd.port.post.mk>
