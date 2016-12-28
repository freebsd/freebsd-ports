# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tcpsocketpipe
PORTVERSION=	1.8.2
CATEGORIES=	net ruby
MASTER_SITES=	http://dev.ctor.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	socketproxy.rb
EXTRACT_SUFX=	# none
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	# none

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library to create I/O pipes for TCP socket tunneling

USE_RUBY=	yes

NO_BUILD=	yes
PLIST_FILES=	%%RUBY_SITELIBDIR%%/socketproxy.rb

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/socketproxy.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
