# New ports collection makefile for:	mod_watch4
# Date created:			11 Octber 2003
# Whom:				Toshiya SAITOH <toshiya@saitoh.nu>
#
# $FreeBSD$
#

PORTNAME=	mod_watch
PORTVERSION=	4.3
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./0/g}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	toshiya@saitoh.nu
COMMENT=	An Apache2 module to monitor bandwidth usage, for use with MRTG etc

RUN_DEPENDS=	mrtg:${PORTSDIR}/net-mgmt/mrtg

NO_PACKAGE=	"Binary package distribution is prohibited by license"
NO_CDROM=	"Commercial distfile distribution is prohibited by license"

USE_PERL5_RUN=	yes
USE_APACHE=	yes
WITH_APACHE2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	Makefile.dso

MAKE_ARGS+=	APXS="${APXS}"

LATEST_LINK=	mod_watch4

ALL_TARGET=	build

DOCS=			apache2mrtg.shtml index.shtml mailto.js mod_watch.shtml style.css
DOCS_HTMLIMAGES=	apache-header-476-62.png mrpixel.gif mrtg-bar.png \
			sun-logo.jpg wave1.jpg

do-install:
	${APXS} -i -a -n watch ${WRKSRC}/mod_watch.la
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
