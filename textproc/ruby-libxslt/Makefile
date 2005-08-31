# New ports collection makefile for:	ruby-libxslt
# Date created:		19 July 2002
# Whom:	      		Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxslt
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubynet.org/modules/xml/libxslt/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	A developer friendly libxslt binding for Ruby

BUILD_DEPENDS=	${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2 \
		${LOCALBASE}/bin/xslt-config:${PORTSDIR}/textproc/libxslt \
		${NONEXISTENT}:${PORTSDIR}/${RUBY_LIBXML_PORT}:patch
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xml/libxml.so:${PORTSDIR}/textproc/ruby-libxml

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/xml/libxslt.so
USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_LIBXML_PORT=	textproc/ruby-libxml
RUBY_LIBXML_WRKSRC_CMD=	cd ${PORTSDIR}/${RUBY_LIBXML_PORT} && ${MAKE} -V WRKSRC

INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 504100
BROKEN=		"Configure fails on FreeBSD >= 5.x"
.endif

post-extract:
	@${MKDIR} ${WRKDIR}
	@${LN} -fs `${RUBY_LIBXML_WRKSRC_CMD}` ${WRKDIR}/libxml

.include <bsd.port.post.mk>
