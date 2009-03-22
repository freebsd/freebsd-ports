# New ports collection makefile for:	ruby-libxml
# Date created:		09 July 2002
# Whom:	      		Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.1.3
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	libxml
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A friendly API to libxml for Ruby

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_RUBY=	yes
USE_ICONV=	yes
USE_LDCONFIG=	${RUBY_SITEARCHLIBDIR}/xml

EXT_ARGS=	--with-iconv-dir=${LOCALBASE} \
		--with-iconv-lib=${LOCALBASE}/lib \
		--with-iconv-include=${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|libxml_ruby|xml/libxml_ruby|' \
	    ${WRKSRC}/lib/libxml.rb

do-configure:
	cd ${WRKSRC}/ext/libxml && ${RUBY} extconf.rb build ${EXT_ARGS}

do-build:
	cd ${WRKSRC}/ext/libxml && ${MAKE}

do-install:
	${INSTALL} -d ${RUBY_SITELIBDIR}/xml ${RUBY_SITELIBDIR}/libxml ${RUBY_SITEARCHLIBDIR}/xml
	${INSTALL_DATA} ${WRKSRC}/lib/libxml.rb ${RUBY_SITELIBDIR}/xml
	(cd ${WRKSRC}/lib/libxml && ${COPYTREE_SHARE} \*.rb ${RUBY_SITELIBDIR}/libxml)
	${INSTALL_DATA} ${WRKSRC}/ext/libxml/libxml_ruby.so ${RUBY_SITEARCHLIBDIR}/xml/

.include <bsd.port.mk>
