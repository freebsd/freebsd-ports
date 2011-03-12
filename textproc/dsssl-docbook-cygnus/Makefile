# New ports collection makefile for:   stylesheets
# Date created:        2 Feb 2000
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dsssl-docbook-cygnus
PORTVERSION=	1.44
CATEGORIES=	textproc
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/docbook-tools/docware/SOURCES/
DISTNAME=	stylesheets
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook DSSSL stylesheets of Cygnus Slution

RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/dsssl/modular/frames/navbar.htm:${PORTSDIR}/textproc/dsssl-docbook-modular \
		jade:${PORTSDIR}/textproc/jade

DEPRECATED=     Distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/stylesheets
SCRIPTS_ENV=	DB_DATA="${DB_SCRIPTS} cygnus-both.dsl"

STYLESHEETSDIR=	${PREFIX}/share/sgml/docbook/dsssl/cygnus
DB_SCRIPTS=	db2dvi.sh db2html.sh db2pdf.sh db2ps.sh db2rtf.sh

do-install:
	${MKDIR} ${STYLESHEETSDIR}
	cd ${WRKSRC}; \
	${RM} -f *~ *.orig; \
	${INSTALL_DATA} ChangeLog bosak-db3.dsl cygnus-both.dsl dbtohtml.dsl \
		${STYLESHEETSDIR}; \
	${INSTALL_DATA} stylesheets.cat ${STYLESHEETSDIR}/catalog
.for f in ${DB_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin/`${BASENAME} ${f} .sh`
.endfor

.include <bsd.port.mk>
