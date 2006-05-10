# New ports collection makefile for:   thailocale
# Date created:        5 January 2005
# Whom:                Thawatchai Piyawat <piyawat@usablelabs.com>
#
# $FreeBSD$
#

PORTNAME=	thailocale
PORTVERSION=	0.11
CATEGORIES=	misc
MASTER_SITES=	http://www.usablelabs.com/download/

MAINTAINER=	piyawat@usablelabs.com
COMMENT=	A locale for Thai in Thailand, TIS-620 character set

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

pre-configure: 
	${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|" ${WRKSRC}/Makefile 
 
post-install: 
	@${ECHO_MSG} 
	@${CAT} ${PKGMESSAGE} 
	@${ECHO_MSG}

.include <bsd.port.mk>
