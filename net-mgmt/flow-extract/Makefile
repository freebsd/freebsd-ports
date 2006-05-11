# New ports collection makefile for:	flow-extract
# Date created:				2003 Mar 14
# Whom:					Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	flow-extract
PORTVERSION=	2.4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://security.uchicago.edu/tools/net-forensics/files/
DISTNAME=	flowextract-${PORTVERSION}
EXTRACT_SUFX=	.cpio.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cisco NetFlow awk-like extracting tool

BUILD_DEPENDS=	flow-cat:${PORTSDIR}/net-mgmt/flow-tools

EXTRACT_AFTER_ARGS=	| ${CPIO} -idmu

post-patch:	patch-makefile

patch-makefile:
		@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			${WRKSRC}/Makefile

do-install:
		@${INSTALL_PROGRAM}	${WRKSRC}/flow-extract ${PREFIX}/bin
		@${INSTALL_MAN}		${WRKSRC}/flow-extract.1 ${PREFIX}/man/man1

MAN1=		flow-extract.1
PLIST_FILES=	bin/flow-extract

.include <bsd.port.mk>
