# New ports collection makefile for:	geheimnis
# Date created:		09 Feb 2001
# Whom:			Pekka Nikander <Pekka.Nikander@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	geheimnis
PORTVERSION=	2
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pnr@iki.fi

USE_KDELIBS_VER=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's,-lqt,,g' ${WRKSRC}/geheimnis/Makefile.in

post-configure:
	@cd ${WRKSRC}/geheimniskeepopen && \
		${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} \
		${CONFIGURE_ARGS}

post-build:
	@cd ${WRKSRC}/geheimniskeepopen && \
		${SETENV} ${MAKE_ENV} ${MAKE}

post-install:
	@cd ${WRKSRC}/geheimniskeepopen && \
		${SETENV} ${MAKE_ENV} ${MAKE} install
	strip ${PREFIX}/bin/geheimniskeepopen
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
