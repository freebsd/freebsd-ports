# New ports collection makefile for:	HOZ - Hacha Open Zource
# Date created:		2005-09-16
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	hoz
PORTVERSION=	1.65
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	File splitter, GTK and CLI versions

USE_GNOME=	#
USE_GMAKE=	yes

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	README

OPTIONS=	CLI	"CLI interface" on \
		GTK2	"GTK interface" on \
		LANG_ES	"Spanish translation"	off \
		LANG_EN	"English translation"	on \
		LANG_FR	"French translation"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GTK2)
USE_GNOME+=	gtk20
.endif

.if defined(WITHOUT_CLI)
ALL_TARGET=	gtk
.else
PLIST_FILES+=	bin/hoz
.endif

.if defined(WITHOUT_GTK2)
ALL_TARGET=	cli
.else
PLIST_FILES+=	bin/ghoz
.endif

.if defined(WITH_LANG_ES)
MAKE_ENV+=	LANG="-DHOZ_LANG_ES"
.endif

.if !defined(WITHOUT_LANG_EN)
MAKE_ENV+=	LANG="-DHOZ_LANG_EN"
.endif

.if defined(WITH_LANG_FR)
MAKE_ENV+=	LANG="-DHOZ_LANG_FR"
.endif

do-install:
.if !defined(WITHOUT_CLI)
	${INSTALL_PROGRAM} ${WRKSRC}/hoz ${PREFIX}/bin
.endif
.if !defined(WITHOUT_GTK2)
	${INSTALL_PROGRAM} ${WRKSRC}/ghoz ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
