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
		> ${SYSSRC}/pmfrc.default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmf ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pmf
	${INSTALL_DATA} ${SYSSRC}/NEWS ${PREFIX}/share/pmf
	${INSTALL_DATA} ${SYSSRC}/pmfrc.default ${PREFIX}/share/pmf
	@${MKDIR} ${PREFIX}/share/pmf/helpfiles
	${INSTALL_DATA} ${SYSSRC}/helpfiles/.pmfrc ${PREFIX}/share/pmf/helpfiles
	${INSTALL_DATA} ${SYSSRC}/helpfiles/* ${PREFIX}/share/pmf/helpfiles
	@${MKDIR} ${PREFIX}/share/examples/pmf
	${INSTALL_DATA} ${XMPSRC}/.pmfrc ${PREFIX}/share/examples/pmf/dot.pmfrc
	${INSTALL_DATA} ${XMPSRC}/* ${PREFIX}/share/examples/pmf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pmf
	${INSTALL_DATA} ${DOCSRC}/* ${PREFIX}/share/doc/pmf
.endif

.include <bsd.port.mk>
