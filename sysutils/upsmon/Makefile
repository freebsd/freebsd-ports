# New ports collection makefile for:	upsmon
# Date created:		5 Oct 1998
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	upsmon
PORTVERSION=	2.1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://newcorridor.com/pub/upsmon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic UPS monitor for the APC SmartUPS devices

MAKEFILE=	makefile.bsdi
NO_PACKAGE=	"must provide without modifications"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/upsstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/upsmond ${PREFIX}/sbin

	${SED} -e 's#!!PREFIX!!#${PREFIX}#g' ${FILESDIR}/upsmon.sh \
	> ${PREFIX}/etc/rc.d/upsmon.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/upsmon.sh

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

post-install:
	${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>
