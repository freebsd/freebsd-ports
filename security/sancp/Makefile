# New ports collection makefile for:	sancp
# Date created:				10 Feb 2005
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sancp
PORTVERSION=	1.6.1
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A network connection profiler

ALL_TARGET=	bsd
USE_RC_SUBR=	sancp.sh
SUB_FILES=	pkg-message

PORTDOCS=	CHANGES INSTALL ISSUES README \
		SETUP fields.LIST LICENSE

post-extract:
	@cd ${WRKSRC} && ${MV} LICENSE docs/

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_PROGRAM} ${WRKSRC}/sancp ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/etc/sancp/sancp.conf ${PREFIX}/etc/sancp.conf-dist
	@${CP} -n ${PREFIX}/etc/sancp.conf-dist ${PREFIX}/etc/sancp.conf

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
