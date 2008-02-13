# New ports collection makefile for:	ruby-libxml
# Date created:		09 July 2002
# Whom:	      		Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	0.5.2.0
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	libxml
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	gahr@gahr.ch
COMMENT=	A friendly API to libxml for Ruby

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
					xml2-config:${PORTSDIR}/textproc/libxml2 \

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/xml/libxml_so.so \
					%%RUBY_SITELIBDIR%%/xml/libxml.rb
PLIST_DIRS=	%%RUBY_SITEARCHLIBDIR%%/xml \
				%%RUBY_SITELIBDIR%%/xml

USE_RUBY=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%%PREFIX%%%|${PREFIX}|g' \
		${WRKSRC}/ext/xml/extconf.rb

do-build:
	cd ${WRKSRC} && rake test

do-install:
	cd ${WRKSRC} && rake install

.include <bsd.port.mk>
