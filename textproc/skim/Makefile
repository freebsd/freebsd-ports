# New ports collection makefile for:    skim
# Date created:		21 July 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	skim
PORTVERSION=	0.9.4
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freedesktop.org/~cougar/skim/downloads/
MASTER_SITE_SUBDIR= scim

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	An input method platform based on SCIM library and KDE/QT

LIB_DEPENDS=	scim-1.0.4:${PORTSDIR}/textproc/scim

USE_KDELIBS_VER=3
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -D__STDC_ISO_10646__" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

pre-configure:
	${REINPLACE_CMD} "s,-pedantic,,g; \
		s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure
	${REINPLACE_CMD} "s, | .*freebsd\*)$$,*),g" ${WRKSRC}/admin/ltmain.sh

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type make post-install

.include <bsd.port.mk>
