# New ports collection makefile for:	duo
# Date created:				17 Jul 2011
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	duo
PORTVERSION=	1.8
CATEGORIES=	security
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}security/${PORTNAME}_unix/
DISTNAME=	${PORTNAME}_unix-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Duo unix integration package

LICENSE=	GPLv2

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS=	--with-pam=${PREFIX}/lib/security --sysconfdir=${ETCDIR}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

MAN3=		duo.3
MAN8=		login_duo.8 pam_duo.8

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/login_duo/login_duo.8
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pam_duo/pam_duo.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
