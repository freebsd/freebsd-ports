# New ports collection makefile for:	mod_watch
# Date created:			18 August 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_watch
PORTVERSION=	2.4
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_watch/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}204
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

APXS?=		${LOCALBASE}/sbin/apxs

DOCS=	apache2mrtg.html dbm-client.html dbm-server.html index.shtml \
	mod_watch.html style.css

FIXCONVERT=	CHANGES.TXT convert.pl index.shtml

post-patch:
.for f in ${FIXCONVERT}
	@${SED} -e 's:convert.pl:convertdbm.pl:g' < ${WRKSRC}/${f} \
		> ${WRKSRC}/${f}.tmp
	@${MV} ${WRKSRC}/${f}.tmp ${WRKSRC}/${f}
.endfor

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_watch.c

do-install:
	${APXS} -i -A -n watch ${WRKSRC}/mod_watch.so
	${INSTALL_SCRIPT} ${WRKSRC}/apache2mrtg.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mod_watch.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/convert.pl ${PREFIX}/sbin/convertdbm.pl
	${INSTALL_SCRIPT} ${WRKSRC}/dbm-client.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/dbm-server.pl ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/mod_watch/html/Img
	${INSTALL_DATA} ${WRKSRC}/CHANGES.TXT ${PREFIX}/share/doc/mod_watch/
	${INSTALL_DATA} ${WRKSRC}/Img/mrpixel.gif ${PREFIX}/share/doc/mod_watch/html/Img/
	${INSTALL_DATA} ${WRKSRC}/Img/sun-logo.jpg ${PREFIX}/share/doc/mod_watch/html/Img/
	${INSTALL_DATA} ${WRKSRC}/Img/wave1.jpg ${PREFIX}/share/doc/mod_watch/html/Img/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_watch/html/
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
