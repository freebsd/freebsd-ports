# New ports collection makefile for:	qscanplot
# Date created:				9 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qscanplot
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	math
# per distfile survey, mastersite disappeared in March 2003
MASTER_SITES=	# http://www.gae.ucm.es/~gonzalez/qscanplot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to extract data from scanned plots, graphs and figures

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lm ${PTHREAD_LIBS}" \
		QTDIR=${X11BASE} \
		LIBQT=-lqt-mt
MAKE_ENV=	QTDIR=${X11BASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/qscanplot/templates/sample.qscanplotrc

.include <bsd.port.post.mk>
