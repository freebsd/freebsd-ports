# New ports collection makefile for:	Ruby/OpenSSL
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.1.0
CATEGORIES=	security ruby
MASTER_SITES=	http://freesoftware.fsf.org/download/rubypki/
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

DOCS=		ChangeLog README

post-extract:
	${FIND} ${WRKSRC} -type d -name CVS | xargs ${RM} -rf
	${FIND} ${WRKSRC} -type f -name '*~' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/test/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
