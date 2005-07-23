# New ports collection makefile for:	gprename
# Date created:				2004-03-15
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gprename
PORTVERSION=	1.24
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Perl script for renaming multiple files

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk:${PORTSDIR}/x11-toolkits/p5-Gtk

NO_BUILD=	yes
PLIST_DIRS=	share/gprename/languages share/gprename/pixmaps share/gprename
PLIST_FILES=	bin/gprename share/gprename/pixmaps/gprename_icon64.xpm share/gprename/gprename.pl share/gprename/langs.pl
USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.for ii in en es.ISO-8859-1 es.UTF-8 fr.ISO-8859-1 fr.UTF-8 zh_TW.Big5 \
	zh_TW.UTF-8 pl.ISO-8859-2 pl.UTF-8
PLIST_FILES+=	share/gprename/languages/lang.${ii}
.endfor

pre-install:
.if !defined(NOPORTDOCS)
PLIST_DIRS+=	share/doc/gprename
PLIST_FILES+=	share/doc/gprename/README
.endif

do-install:
	${MKDIR} ${DATADIR}
	${CP} -pPR ${WRKSRC}/languages ${WRKSRC}/pixmaps ${DATADIR}
.for ii in gprename langs
	${INSTALL_SCRIPT} ${WRKSRC}/${ii}.pl ${DATADIR}
.endfor
	${SED} 's:PREFIX:${PREFIX}:g' < ${FILESDIR}/gprename \
		> ${WRKDIR}/gprename
	${INSTALL_SCRIPT} ${WRKDIR}/gprename ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
