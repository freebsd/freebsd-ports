# ex:ts=8
# New ports collection makefile for:	dirtree
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dirtree
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://home.pages.at/kingleo/development/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	LeoArg.2:${PORTSDIR}/devel/leoarg \
		intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_REINPLACE=	yes

MAN1=	dirtree.1

post-patch:
.for f in src/CppDir.hh src/CppDir.cpp
	${REINPLACE_CMD} -e 's,^class ostream;$$,#include <ostream.h>,g' \
		-e 's,ostream\([^.]\),std::ostream\1,g' ${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e 's,const.*PATH_MAX =\(.*\);,#define\
		PATH_MAX \1,g' ${WRKSRC}/src/xgetcwd.cpp

.include <bsd.port.mk>
