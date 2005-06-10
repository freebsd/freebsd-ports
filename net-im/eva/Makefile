# New ports collection makefile for:	eva
# Date created:			16 April 2005
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	evaq
PORTVERSION=	0.2.1
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	eva-${PORTVERSION}-20050406

MAINTAINER=	hamigua@cuc.cn
COMMENT=	QQ IM Client for KDE3

WRKSRC=		${WRKDIR}/eva-${PORTVERSION}
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"does not compile"
.endif

pre-patch:
	${REINPLACE_CMD} -e 's/-pedantic //g; s/-O2//g; \
		s/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
