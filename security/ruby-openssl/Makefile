# New ports collection makefile for:	Ruby/OpenSSL
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.0.3
CATEGORIES=	security ruby
MASTER_SITES=	http://klokan.sh.cvut.cz/~rokosm/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ossl-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_OPENSSL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-openssl-include="${OPENSSLBASE}/include/openssl" \
		--with-openssl-lib="${OPENSSLBASE}/lib"
INSTALL_TARGET=	site-install

post-extract:
	find ${WRKSRC} -type d -name CVS | xargs ${RM} -rf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/test/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
