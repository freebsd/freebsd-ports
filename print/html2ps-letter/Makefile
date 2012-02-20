# New ports collection makefile for:	html2ps-letter
# Date created:		Sat Nov 22 12:54:50 CET 1997
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	html2ps
DISTVERSION=	1.0b7
PORTEPOCH=	1
CATEGORIES=	print www perl5
MASTER_SITES=	http://user.it.uu.se/~jan/ \
		http://fossies.org/unix/www/
PKGNAMESUFFIX=	-${PAPERSIZE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to PostScript converter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		weblint:${PORTSDIR}/www/weblint

NO_BUILD=	yes
USE_PERL5=	yes
USE_GHOSTSCRIPT_RUN=	yes

SUB_FILES=	html2psrc
SUB_LIST=	PAPERSIZE="${PAPERSIZE}"

MAN1=		html2ps.1
MAN5=		html2psrc.5
PLIST_FILES=	bin/html2ps \
		%%DATADIR%%/html2ps.html \
		%%DATADIR%%/html2psrc \
		%%DATADIR%%/hyphen.tex
PLIST_DIRS=	%%DATADIR%%

PAPERSIZE?=	letter

post-patch:
	@${REINPLACE_CMD} -e \
		's|exec perl|exec ${PERL}| ; \
		 s|/it/sw/share/www/lib/html2ps|${DATADIR}|' ${WRKSRC}/html2ps

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2ps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2ps.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2psrc.5 ${MAN5PREFIX}/man/man5
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/html2psrc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html2ps.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hyphen.tex ${DATADIR}

.include <bsd.port.mk>
