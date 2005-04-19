# New ports collection makefile for:	smc-milter
# Date created:		30 March 2005
# Whom:			Andrey E. Shevtsov
#
# $FreeBSD$
#

PORTNAME=	smc-milter
PORTVERSION=	1.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	milter

MAINTAINER=	nyxo@dnuc.polyn.kiae.su
COMMENT=	A non-context email filter

BUILD_DEPENDS=	${LOCALBASE}/lib/libbind_r.a:${PORTSDIR}/dns/bind84

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

NOMAN=

post-patch:
	@${REINPLACE_CMD} -e 's|\/opt\/SMC|${PREFIX}\/etc\/smc|g' \
		${WRKSRC}/smc-milter.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/smc-milter.sh \
		${PREFIX}/etc/rc.d/smc-milter.sh.sample

.include <bsd.port.mk>
