# New ports collection makefile for:	mosfet-liquid
# Date created:		August 22 2001
# Whom:			Michiel De Wilde <michiel.dewilde@rug.ac.be>
#
# $FreeBSD$
#

PORTNAME=	mosfet-liquid
PORTVERSION=	0.9.4
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.mosfet.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@geeksrus.net

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14 \
		autoconf213:${PORTSDIR}/devel/autoconf213

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

MAKE_ENV+=	PATH=${WRKDIR}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${WRKDIR}/bin:${PATH}

pre-everything::
	${MKDIR} ${WRKDIR}/bin
	-$(LN) -sf ${LOCALBASE}/bin/aclocal14 ${WRKDIR}/bin/aclocal
	-$(LN) -sf ${LOCALBASE}/bin/autoconf213  ${WRKDIR}/bin/autoconf
	-$(LN) -sf ${LOCALBASE}/bin/autoheader213  ${WRKDIR}/bin/autoheader
	-$(LN) -sf ${LOCALBASE}/bin/automake14  ${WRKDIR}/bin/automake

pre-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
