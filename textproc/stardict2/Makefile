# Ports collection makefile for:	stardict2
# Date created:			13 April 2003
# Whom:				Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	stardict2
PORTVERSION=	2.0.0
CATEGORIES=	chinese
MASTER_SITES=	http://reciteword.cosoft.org.cn/yaoguang/myapps/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/stardict2/
DISTFILES=	stardict-${PORTVERSION}.tar.gz \
		stardict-cdict-big5-${PORTVERSION}.tar.bz2 \
		stardict-cedict-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ce-big5-${PORTVERSION}.tar.bz2

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	English-Chinese dictionary

LIB_DEPENDS=	gnome-2.200:${PORTSDIR}/x11/libgnome \
		gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		bonobo-2.0:${PORTSDIR}/devel/libbonobo \
		bonobo-activation.4:${PORTSDIR}/devel/bonobo-activation

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Configure fails"
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/stardict-${PORTVERSION}

MAN1=		stardict.1

do-extract:
		${MKDIR} ${WRKDIR}
		cd ${WRKDIR} && tar zxf ${DISTDIR}/stardict-2.0.0.tar.gz && \
		tar jxf ${DISTDIR}/stardict-cdict-big5-2.0.0.tar.bz2 && \
		tar jxf ${DISTDIR}/stardict-cedict-big5-2.0.0.tar.bz2 && \
		tar jxf ${DISTDIR}/stardict-xdict-big5-2.0.0.tar.bz2 && \
		tar jxf ${DISTDIR}/stardict-xdict-ce-big5-2.0.0.tar.bz2

post-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cdict-big5-2.0.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cedict-big5-2.0.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-big5-2.0.0/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ce-big5-2.0.0/* ${PREFIX}/share/stardict/dic/

.include <bsd.port.post.mk>
