# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gman
PORTVERSION=	0.9.3
PORTREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gman
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A user-friendly graphical front end for the man system

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview	\
		man2html:${PORTSDIR}/textproc/man2html

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gettext gmake
USE_GNOME=	gtk12

CXXFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>
SHEBANG_LANG+=	perlw
perlw_OLD_CMD=  /usr/bin/perl -w
perlw_CMD=	${LOCALBASE}/bin/perl -w
SHEBANG_FILES=	*.pl

post-patch:
	@${REINPLACE_CMD} -e 's,^CXX =,#CXX =,g' \
		-e 's,^CXXFLAGS =,CXXFLAGS+=,g' \
		-e 's,gtk-config,${GTK_CONFIG},g' \
		-e 's,= /usr,= ${PREFIX},g' \
		-e 's,\-O2,,g' \
		-e 's,\-lgtk \-lgdk \-lpthread ,`${GTK_CONFIG} \-\-libs gthread` ,g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${STAGEDIR}${PREFIX}/bin/gman.cgi
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_MAN} ${WRKSRC}/gman.1x ${STAGEDIR}${MANPREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
