# New ports collection makefile for:	ROMP
# Date created:		24 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	romp
PORTVERSION=	0.2
CATEGORIES=	net ruby
MASTER_SITES=	http://rubystuff.org/romp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} romp.html
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	The Ruby Object Message Proxy

IGNOREFILES=	romp.html

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	client.rb server.rb
DOCS=		romp.html

post-extract:
	${MKDIR} ${WRKSRC}/lib
.for f in romp.rb
	${MV} ${WRKSRC}/${f} ${WRKSRC}/lib/
.endfor
	${CP} ${DISTDIR}/${DIST_SUBDIR}/romp.html ${WRKSRC}/

post-patch:
	${RUBY} -i~ -pe 'sub /^(#include\s*<stdint\.h>)/, "/*\\1*/"' ${WRKSRC}/*.c
	${RUBY} -i~ -pe 'sub /(.*CFLAGS)/, "#\\1/"' ${WRKSRC}/extconf.rb

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
