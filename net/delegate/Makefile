# New ports collection makefile for:	DeleGate
# Version required:		5.9.4
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	delegate5.9.4
PKGNAME=	delegate-5.9.4
CATEGORIES=	net www japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/

MAINTAINER=	max@FreeBSD.org

MAKE_ENV=	PATH=$${PATH}:.

.if defined(BATCH)
pre-build:
	@${ECHO} "MANAGER=root@localhost" >> ${WRKSRC}/DELEGATE_CONF
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
