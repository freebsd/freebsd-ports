# New ports collection makefile for:	pmf
# Date created:		24 Sep 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	pmf
PORTVERSION=	1.13.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/clients/pmf/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/pmfdir/src

SYSSRC=		${WRKSRC}/../system_dir
DOCSRC=		${WRKSRC}/../doc
XMPSRC=		${WRKSRC}/../examples

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${FILESDIR}/pmfrc.default.in \
		> ${WRKSRC}/../system_dir/pmfrc.default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmf ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libdata/pmf/helpfiles
	${INSTALL_DATA} ${SYSSRC}/pmfrc.default ${PREFIX}/libdata/pmf
	${INSTALL_DATA} ${SYSSRC}/NEWS ${PREFIX}/libdata/pmf
	${INSTALL_DATA} ${SYSSRC}/helpfiles/.pmfrc ${PREFIX}/libdata/pmf/helpfiles
	${INSTALL_DATA} ${SYSSRC}/helpfiles/* ${PREFIX}/libdata/pmf/helpfiles
	@${MKDIR} ${PREFIX}/share/doc/pmf
	${INSTALL_DATA} ${DOCSRC}/../doc/* ${PREFIX}/share/doc/pmf
	@${MKDIR} ${PREFIX}/share/examples/pmf
	${INSTALL_DATA} ${XMPSRC}/.pmfrc ${PREFIX}/share/examples/pmf
	${INSTALL_DATA} ${XMPSRC}/* ${PREFIX}/share/examples/pmf

.include <bsd.port.mk>
