# New ports collection makefile for:	apg
# Date created:		1 September 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	apg
PORTVERSION=	2.3.0b
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An automated password generator

.if defined(WITH_CRACKLIB)
LIB_DEPENDS=	crack.1:${PORTSDIR}/security/cracklib
MAKE_ARGS=	-DWITH_CRACKLIB
.endif

MAN1=		apg.1 apgbfm.1
MAN8=		apgd.8
DOCS=		APG_TIPS pronun.txt rfc0972.txt rfc1750.txt

post-extract:
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} u+wx
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} u+w

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgbfm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/man/apg.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgbfm.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgd.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
