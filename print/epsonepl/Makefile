# New ports collection makefile for:	epsonepl
# Date created:		14 February 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	epsonepl
PORTVERSION=	0.2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}ijs-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Printer filter for EPSON EPL-5700L etc"

USE_GHOSTSCRIPT_RUN=	yes

LIB_DEPENDS=	ijs.1:${PORTSDIR}/print/libijs

MAKEFILE=	${FILESDIR}/Makefile

post-extract:
	@cd ${WRKSRC} && ${LS} ijs* | ${GREP} -v ${PORTNAME} | ${XARGS} ${RM}

post-install:
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${PREFIX}/etc
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.apsfilter ${DATADIR}
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>
