# Ports collection makefile for:	stardict2
# Date created:			13 April 2003
# Whom:				Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	chinese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	stardict-${PORTVERSION}.tar.bz2 \
		stardict-cdict-big5-2.1.0.tar.bz2 \
		stardict-cedict-big5-2.1.0.tar.bz2 \
		stardict-oxford-big5-2.1.0.tar.bz2 \
		stardict-xdict-big5-2.1.0.tar.bz2 \
		stardict-xdict-ce-big5-2.1.0.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English-Chinese dictionary

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	libgnome libgnomeui libbonobo gconf2

MAN1=		stardict.1

post-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cdict-big5-2.1.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cedict-big5-2.1.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-oxford-big5-2.1.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-big5-2.1.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ce-big5-2.1.0/* ${PREFIX}/share/stardict/dic/

.include <bsd.port.mk>
