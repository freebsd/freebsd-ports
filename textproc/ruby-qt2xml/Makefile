# New ports collection makefile for:	Ruby-qt2xml
# Date created:		23 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2xml
PORTVERSION=	0.11
CATEGORIES=	textproc x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-qt2-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}

RUBY_QT2_PORTDIR=	${PORTSDIR}/x11-toolkits/ruby-qt2

MD5_FILE=	${RUBY_QT2_PORTDIR}/distinfo

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/qt2/modules/xml
CONFIGURE_ARGS=	--with-qt2-include=${X11BASE}/include/qt2 \
		--with-qt2-lib=${X11BASE}/lib \
		--with-qt2=qt2 \
		--with-x11-dir=${X11BASE}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-extract:
	cd ${WRKSRC}/examples/domexample && \
	${RM} domtest1.cc domtest1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/qt2xml
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/qt2xml/
.endif

.include <bsd.port.mk>
