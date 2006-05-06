# New ports collection makefile for:	gaim-ignorance
# Date created:		17 April 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	ignorance
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://thefnords.googlepages.com/
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Adds filtering capabilities to gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

DEPRECATED=	The author has taken down his site and has ceased developing this program

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/ignorance.conf/ignorance.conf.sample/g" ${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/ignorance.conf ${WRKSRC}/ignorance.conf.sample

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ignorance ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	if ${TEST} ! -f ${PREFIX}/etc/gaim/ignorance.conf; then \
		${CP} ${PREFIX}/etc/gaim/ignorance.conf.sample ${PREFIX}/etc/gaim/ignorance.conf; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
