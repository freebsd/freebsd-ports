# New ports collection makefile for:	qscanplot
# Date created:				9 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qscanplot
PORTVERSION=	0.4
CATEGORIES=	math
MASTER_SITES=	http://www.gae.ucm.es/~gonzalez/qscanplot/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lm ${PTHREAD_LIBS}" \
		QTDIR=${X11BASE} \
		LIBQT=-lqt2
MAKE_ENV=	QTDIR=${X11BASE}

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/qscanplot/templates/sample.qscanplotrc

.include <bsd.port.mk>
