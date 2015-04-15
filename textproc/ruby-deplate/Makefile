# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=		deplate
PORTVERSION=		0.8.5
CATEGORIES=		textproc ruby
MASTER_SITES=		SF
PKGNAMEPREFIX=		${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=		ruby

MAINTAINER=		ruby@FreeBSD.org
COMMENT=		Ruby tool for converting wiki-like markup

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE.TXT

WRKSRC=			${WRKDIR}/${PORTNAME}

USES=		zip
USE_RUBY=		yes
USE_RUBY_SETUP=		yes

.include <bsd.port.pre.mk>

post-build:
	${RM} -r ${WRKSRC}/lib/deplate/themes/navbar-right.html

.if ${RUBY_VER} >= 2.2
BROKEN=		Does not build
.endif

.include <bsd.port.post.mk>
