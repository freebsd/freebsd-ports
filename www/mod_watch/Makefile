# New ports collection makefile for:	mod_watch
# Date created:			18 August 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_watch
PORTVERSION=	3.12
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_watch/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

APXS?=		${LOCALBASE}/sbin/apxs
MAKE_ARGS+=	APXS="${APXS}"

ALL_TARGET=	build-dynamic

DOCS=	apache2mrtg.html index.shtml mailto.js mod_watch.html style.css
DOCS_HTMLIMAGES=	apache-header-476-62.png mrpixel.gif mrtg-bar.png \
			sun-logo.jpg wave1.jpg

post-patch:
	${PERL} -pi -e "s@^APXS.*@@" ${WRKSRC}/Makefile

do-install:
	${APXS} -i -A -n watch ${WRKSRC}/mod_watch.so
	${INSTALL_SCRIPT} ${WRKSRC}/apache2mrtg.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mod_watch.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/nfields.pl ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}/html/Img
	${INSTALL_DATA} ${WRKSRC}/CHANGES.TXT ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${DOCSDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/html/
.endfor
.for f in ${DOCS_HTMLIMAGES}
	${INSTALL_DATA} ${WRKSRC}/Img/${f} ${DOCSDIR}/html/Img/
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
