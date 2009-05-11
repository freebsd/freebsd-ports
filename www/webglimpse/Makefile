# New ports collection makefile for:    WebGlimpse
# http://webglimpse.net/
# Date created:                         2 Nov 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	webglimpse
PORTVERSION=	1.6
CATEGORIES=	www textproc
MASTER_SITES=	ftp://ftp.deva.net/pub/sources/ir/glimpse/
DISTNAME=	${PKGNAME}.src

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	WWW interface to Glimpse search engine

RUN_DEPENDS=	glimpse:${PORTSDIR}/textproc/glimpse

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.edu

USE_PERL5=	yes
USE_APACHE=	1.3
NO_CDROM=	depends on glimpse
NO_BUILD=	yes

pre-configure:
.for i in wginstall wginstall.pl
	cd ${WRKSRC}; ${CP} $i $i.tmp; \
		${SED} s=%PERL%=${PERL}= < $i.tmp > $i
.endfor

do-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 ${WWWDIR}/
.if defined(PACKAGE_BUILDING)
	${INSTALL_DATA} ${FILESDIR}/.wgsiteconf ${WWWDIR}/
.endif
	cd ${WRKSRC}; ./wginstall
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${DOCSDIR}/
.endif

.include <bsd.port.mk>
