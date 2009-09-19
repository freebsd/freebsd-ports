# Ports collection makefile for:	rubygem-passenger
# Date created:				Dec 18, 2008
# Whom:					Jacob Atzen <jatzen@gmail.com>
#
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	2.2.5
CATEGORIES=	www rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	gems

MAINTAINER=	jatzen@gmail.com
COMMENT=	Apache module for running Ruby on Rails and Rack applications

BUILD_DEPENDS=	rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-rack>=0.1.0:${PORTSDIR}/www/rubygem-rack

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

USE_APACHE=	2.2+
USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/passenger-config \
		bin/passenger-install-apache2-module \
		bin/passenger-make-enterprisey \
		bin/passenger-memory-stats \
		bin/passenger-spawn-server \
		bin/passenger-status \
		bin/passenger-stress-test \
		bin/passenger-install-nginx-module

post-install:
	(${PREFIX}/bin/passenger-install-apache2-module --auto )
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
