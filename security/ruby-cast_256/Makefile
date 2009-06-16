# New ports collection makefile for:	Ruby/CAST-256
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cast_256
PORTVERSION=	1.0
CATEGORIES=	security ruby
MASTER_SITES=	http://www.s-direktnet.de/homepages/neumann/Data/Michael/Kryptologie/Cast/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby_${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby extension library which implements CAST-256 encryption

USE_ZIP=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/gcc
INSTALL_TARGET=	site-install

DOCS=		../readme.txt
EXAMPLES=	../test.rb

post-extract:
	${ECHO_CMD} >> ${WRKSRC}/cast_256.hpp
	( \
		${ECHO_CMD} 'require "mkmf"'; \
		${ECHO_CMD} 'have_library("stdc++")'; \
		${ECHO_CMD} 'create_makefile("rcast_256")'; \
	) > ${WRKSRC}/${RUBY_EXTCONF}
	${MKDIR} ${WRKSRC}/lib
	${MV} ${WRKSRC}/../cast_256.rb ${WRKSRC}/lib/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
