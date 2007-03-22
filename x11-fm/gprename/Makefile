# New ports collection makefile for:	gprename
# Date created:				2004-03-15
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gprename
PORTVERSION=	2.1
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Perl script for renaming multiple files

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

SUB_FILES=	gprename

PORTDOCS=	README
PLIST_FILES=	bin/gprename \
		%%DATADIR%%/COPYING \
		%%DATADIR%%/bin/gprename.pl \
		%%DATADIR%%/languages/lang.en \
		%%DATADIR%%/languages/lang.es.ISO-8859-1 \
		%%DATADIR%%/languages/lang.es.UTF-8 \
		%%DATADIR%%/languages/lang.fr.ISO-8859-1 \
		%%DATADIR%%/languages/lang.fr.UTF-8 \
		%%DATADIR%%/languages/lang.pl.ISO-8859-2 \
		%%DATADIR%%/languages/lang.pl.UTF-8 \
		%%DATADIR%%/languages/lang.pt-br.ISO-8859-1 \
		%%DATADIR%%/languages/lang.pt-br.UTF-8 \
		%%DATADIR%%/languages/langs.pl \
		%%DATADIR%%/icon/gprename_icon.png
PLIST_DIRS=	%%DATADIR%%/icon \
		%%DATADIR%%/languages \
		%%DATADIR%%/bin \
		%%DATADIR%%

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gprename ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DATADIR}
	@${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gprename.pl ${DATADIR}/bin
	@${MKDIR} ${DATADIR}/languages
	${INSTALL_DATA} ${WRKSRC}/languages/lang.* ${DATADIR}/languages
	${INSTALL_DATA} ${WRKSRC}/languages/langs.pl ${DATADIR}/languages
	@${MKDIR} ${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/gprename_icon.png ${DATADIR}/icon/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
