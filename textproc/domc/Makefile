# ex:ts=8
# New ports collection makefile for:	domc
# Date created:			Oct 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	domc
PORTVERSION=	0.6.0
CATEGORIES=	textproc
MASTER_SITES=	http://users.erols.com/mballen/domc/src/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		mba:${PORTSDIR}/devel/libmba

SHLIB_MAJOR=	0

USE_REINPLACE=	yes
CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}" INSTDIR=${PREFIX}
ALL_TARGET=	# empty
INSTALLS_SHLIB=	yes

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
		-e "s|gcc|${CC}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
