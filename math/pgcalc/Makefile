# New ports collection makefile for:	PG Calculator
# Date created:				20 Mar 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pgcalc2
DISTVERSION=	2.2-10
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	http://www.pgcalc.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful scientific skinnable calculator

USE_QT_VER=	3
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	ARTS	"Build with aRts support"	on

.include <bsd.port.pre.mk>

.if !defined(WITH_ARTS)
CONFIGURE_ARGS+=	--without-arts
.endif

post-extract:
# Fix permissions for ``make clean'' to work
	@${CHMOD} 755 ${WRKSRC}/skins/HP49G+ ${WRKSRC}/admin/install-sh
	@${REINPLACE_CMD} -e 's,LIBS)$$,& $$(LIBPTHREAD),' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -E 's,cp ([^-]*).* -r$$,${CP} -r \1,' \
		${WRKSRC}/Makefile.in
# Remove backup leftovers (since installs via recursive copy)
	@${FIND} ${WRKSRC}/skins -name \*~ -delete
# Allow it to find its own skins
	@${REINPLACE_CMD} -e 's,SkinPath =,& QString("${PREFIX}/share/apps/${PORTNAME}/skins/"); //,' \
		${WRKSRC}/src/pgcalc.cpp

.include <bsd.port.post.mk>
