# New ports collection makefile for:	bsdsar
# Date created:				12 June 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	bsdsar
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.googlebit.com/bsdsar/

MAINTAINER=	eric@trinitel.com
COMMENT=	System Activity Reporter for FreeBSD

NO_BUILD=	yes

do-install:
.for file in bsdsar bsdsar_gather
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/bsdsar.conf ${PREFIX}/etc/bsdsar.conf.sample
.if !exists(${PREFIX}/etc/bsdsar.conf)
	${CP} ${PREFIX}/etc/bsdsar.conf.sample ${PREFIX}/etc/bsdsar.conf
.endif
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
