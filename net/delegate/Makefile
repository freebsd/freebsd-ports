# New ports collection makefile for:	DeleGate
# Version required:		5.9.1
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.14 1998/11/09 09:24:20 max Exp $
#

DISTNAME=	delegate5.9.1
PKGNAME=	delegate-5.9.1
CATEGORIES=	net www japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/

MAINTAINER=	max@FreeBSD.ORG

MAKE_ENV=	PATH=$${PATH}:.

.if defined(BATCH)
pre-build:
	@echo "MANAGER=root@localhost" >> ${WRKSRC}/DELEGATE_CONF
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/share/examples/delegate
	${INSTALL_DATA} ${FILESDIR}/delegated.sh \
	   ${PREFIX}/share/examples/delegate
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.txt \
	  ${PREFIX}/share/doc/delegate
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
