# New ports collection makefile for:	DeleGate
# Version required:		4.3.4
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1997/09/22 00:47:21 max Exp $
#

DISTNAME=	delegate4.3.4
PKGNAME=	delegate-4.3.4
CATEGORIES=	net www japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/

MAINTAINER=	max@FreeBSD.ORG

MAKE_ENV+=	PATH=$${PATH}:.

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
