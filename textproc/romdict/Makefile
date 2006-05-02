# New ports collection makefile for:	romdict
# Date created:				2005-12-18
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Tecnik: ports/textproc/romdict/Makefile,v 1.3 2006/05/01 20:10:08 itetcu Exp $

PORTNAME=	romdict
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	eng-rom-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Dictd database for Eng-Ro dictionary

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:${PORTSDIR}/net/dictd

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib/dictd
	${INSTALL_DATA} ${WRKSRC}/eng-rom.dict.dz ${PREFIX}/lib/dictd/
	${INSTALL_DATA} ${WRKSRC}/eng-rom.index ${PREFIX}/lib/dictd/

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
