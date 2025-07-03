PORTNAME=	commonmarker
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
DISTFILES=	${DISTNAME}.gem
#DIST_SUBDIR=	rubygem

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for libcmark (CommonMark parser)
WWW=		https://github.com/gjtorikian/commonmarker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rb_sys>=0.9<1:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

CARGO_BUILD=	no
CARGO_INSTALL=	no
GEM_ENV=	MAKE=gmake
GEMFILES=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	yes

.include <bsd.port.mk>
