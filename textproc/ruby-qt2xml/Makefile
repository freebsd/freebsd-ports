# New ports collection makefile for:	Ruby-qt2xml
# Date created:		23 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2xml
PORTVERSION=	${RUBY_QT2_PORTVERSION}
PORTREVISION=	${RUBY_QT2_PORTREVISION}
CATEGORIES=	textproc x11-toolkits ruby
MASTER_SITES=	${RUBY_QT2_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_QT2_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${RUBY_QT2_WRKSRC}/modules/xml
CONFIGURE_ARGS=	${RUBY_QT2_CONFIGURE_ARGS}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endif

.include "${.CURDIR}/../../x11-toolkits/ruby-qt2/Makefile.common"
.include <bsd.port.mk>
