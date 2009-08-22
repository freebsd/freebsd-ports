# New ports collection makefile for:	eva
# Date created:			16 April 2005
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	eva
PORTVERSION=	0.4.1
PORTREVISION=	6
CATEGORIES=	net-im kde
MASTER_SITES=	SF/${PORTNAME}q/${PORTNAME}-0.4/Eva%20${PORTVERSION}

PATCH_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
PATCHFILES=	eva-0.4.1_20070504.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QQ IM Client for KDE3

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22 autoconf:262
USE_GMAKE=	yes
USE_BZIP2=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|^\(LIBS\ =\ @LIBS@\)|\1 -pthread|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's/-pedantic //g; s/-O2//g; \
		s/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
