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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW interface to Glimpse search engine

RUN_DEPENDS+=	${LOCALBASE}/etc/apache/httpd.conf:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS+=	glimpse:${PORTSDIR}/textproc/glimpse

WRKSRC=		${WRKDIR}/webglimpse-1.6.edu

NO_CDROM=	depends on glimpse
USE_PERL5=	yes
NO_BUILD=	yes

pre-configure:
.for i in wginstall wginstall.pl
	cd ${WRKSRC}; ${CP} $i $i.tmp; \
		${SED} s=%PERL%=${PERL}= < $i.tmp > $i
.endfor

do-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/www/webglimpse
.if defined(PACKAGE_BUILDING)
	${INSTALL_DATA} ${FILESDIR}/.wgsiteconf ${PREFIX}/www/webglimpse
.endif
	cd ${WRKSRC}; ./wginstall
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webglimpse
	cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${PREFIX}/share/doc/webglimpse

.include <bsd.port.mk>
