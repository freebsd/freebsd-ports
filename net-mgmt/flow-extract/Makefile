# New ports collection makefile for:	flow-extract
# Date created:				2003 Mar 14
# Whom:					Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	flow-extract
PORTVERSION=	2.61
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nsit.uchicago.edu/groups/security/tools/flow-extract/
DISTNAME=	flow-extract-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cisco NetFlow awk-like extracting tool

BUILD_DEPENDS=	flow-cat:${PORTSDIR}/net-mgmt/flow-tools

MAN1=		flow-extract.1
PLIST_FILES=	bin/flow-extract

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
		@${INSTALL_PROGRAM}	${WRKSRC}/flow-extract ${PREFIX}/bin
		@${INSTALL_MAN}		${WRKSRC}/flow-extract.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
