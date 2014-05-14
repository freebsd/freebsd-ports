# Created by: Larry Rosenman <ler@lerctr.org>
# $FreeBSD$

PORTNAME=	iog
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.dynw.com/iog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphs Byte Counts for switches/routers/etc

NO_BUILD=	yes
USES=		perl5 tar:tgz
PLIST_SUB=	VERSION=${PORTVERSION}
IOG_USER=	iog
IOG_GROUP=	www

IOGDIR=		${PREFIX}/iog/iog-${PORTVERSION}

do-install:
	PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
	${MKDIR} -m 755 ${STAGEDIR}${IOGDIR}
	${CHMOD} 0600 ${WRKSRC}/iog.cfg
	${CP} ${WRKSRC}/iog.cfg ${WRKSRC}/iog.cfg.sample
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${IOGDIR}
	${CP} ${STAGEDIR}${IOGDIR}/iog.cfg.sample ${STAGEDIR}${IOGDIR}/iog.cfg
	${FIND} ${STAGEDIR}${IOGDIR} -name '*.bak' -or -name '*.orig' -delete
	${LN} -sf ${IOGDIR} ${STAGEDIR}${PREFIX}/iog/iog

.include <bsd.port.mk>
