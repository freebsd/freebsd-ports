# New ports collection makefile for:	snns
# Date created:		2 Febuary 1997
# Whom:			reg@shale.csir.co.za
#
# $FreeBSD$
#

PORTNAME=	snns
PORTVERSION=	4.2
CATEGORIES=	math
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/ \
		ftp://ftp.informatik.uni-stuttgart.de/pub/SNNS/
DISTNAME=	SNNSv${PORTVERSION}
DISTNAME=	SNNSv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully featured neural network simulator

USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/snns --enable-global

post-configure:
	@(${SED} -e "s#%prefix%#${PREFIX}#g" < ${FILESDIR}/snns > ${WRKSRC}/snns)

post-install:
	${MKDIR} ${PREFIX}/snns/examples;
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/snns/examples
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/Readme.license ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/default.cfg ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/help.hdoc ${PREFIX}/snns
	${INSTALL_SCRIPT} ${WRKSRC}/snns ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
