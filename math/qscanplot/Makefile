# New ports collection makefile for:	qscanplot
# Date created:				9 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qscanplot
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	math
# per distfile survey, mastersite disappeared in March 2003
MASTER_SITES=	# http://www.gae.ucm.es/~gonzalez/qscanplot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to extract data from scanned plots, graphs and figures

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_XORG=	x11 xext xinerama
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lm ${PTHREAD_LIBS}" \
		LIBQT=-lqt-mt
MAKE_ENV=	QTDIR=${QT_PREFIX}

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/qscanplot/templates/sample.qscanplotrc

.include <bsd.port.mk>
