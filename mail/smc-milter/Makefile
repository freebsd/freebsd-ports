# New ports collection makefile for:	smc-milter
# Date created:		30 March 2005
# Whom:			Andrey E. Shevtsov
#
# $FreeBSD$
#

PORTNAME=	smc-milter
PORTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	milter

MAINTAINER=	nyxo@dnuc.polyn.kiae.su
COMMENT=	A non-context email filter

BUILD_DEPENDS=	${LOCALBASE}/lib/libbind_r.a:${PORTSDIR}/dns/bind84
LIB_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42

USE_GMAKE=	yes
USE_REINPLACE=	yes

NOMAN=

post-extract:
	@${REINPLACE_CMD} -e 's|\/opt\/SMC|\/usr\/local\/etc\/smc|g ; \
		s|aliases|mail\/aliases|g' \
		${WRKSRC}/smc-milter.h

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/smc-milter.sh \
		${PREFIX}/etc/rc.d/smc-milter.sh

.include <bsd.port.mk>
