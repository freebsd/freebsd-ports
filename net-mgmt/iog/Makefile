# New ports collection makefile for:   net-mgmt/iog
# Date created:        4 May 2003
# Whom:                Larry Rosenman <ler@lerctr.org>
#
# $FreeBSD$
#

PORTNAME=	iog
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.dynw.com/iog/
DISTNAME=	iog-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ler@lerctr.org
COMMENT=	Graphs Byte Counts for switches/routers/etc

NO_BUILD=	yes
USE_PERL5=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}
IOG_USER=	iog
IOG_GROUP=	www

IOGDIR=	${PREFIX}/iog/iog-${PORTVERSION}

do-install:
	@PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
	@${MKDIR} -m 755 ${IOGDIR}
	@${CHMOD} 0600 ${WRKSRC}/iog.cfg
	@${CP} ${WRKSRC}/iog.cfg ${WRKSRC}/iog.cfg.sample
	@${CP} -R ${WRKSRC}/* ${IOGDIR}
	@if [ ! -x ${IOGDIR}/iog.cfg ]; then \
		${CP} ${IOGDIR}/iog.cfg.sample ${IOGDIR}/iog.cfg ; \
	fi
	@${FIND} ${IOGDIR} -name \*.orig -or \
		-name \*.bak | ${XARGS} ${RM} -f
	${CHOWN} -R ${IOG_USER}:${IOG_GROUP} ${PREFIX}/iog
	@if [ -L ${PREFIX}/iog/iog ]; then \
		${ECHO} "Updating ${PREFIX}/iog/iog symbolic link" ; \
		${RM} ${PREFIX}/iog/iog ; \
	fi
	${LN} -sf ${IOGDIR} ${PREFIX}/iog/iog

.include <bsd.port.mk>
