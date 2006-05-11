# New ports collection makefile for:	eva
# Date created:			16 April 2005
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	eva
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evaq

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	QQ IM Client for KDE3

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_BZIP2=	yes
MAKE_ARGS=  ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
            AUTOHEADER="${TRUE}"

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(LIBS\ =\ @LIBS@\)|\1 -pthread|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's/-pedantic //g; s/-O2//g; \
		s/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
