# New ports collection makefile for:	Ruby/OpenSSL
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.1.3
CATEGORIES=	security ruby
MASTER_SITES=	http://savannah.nongnu.org/download/rubypki/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ossl-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_OPENSSL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ossl
CONFIGURE_ARGS=	--with-openssl-include="${OPENSSLBASE}/include/openssl" \
		--with-openssl-lib="${OPENSSLBASE}/lib"
INSTALL_TARGET=	site-install

DOCS=		ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
