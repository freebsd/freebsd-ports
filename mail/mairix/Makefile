# New ports collection Makefile for:	mairix
# Date created:				2003-03-27
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mairix
PORTVERSION=	0.22
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Indexing and searching in Maildir, MH, or mbox folders

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_BISON=	build

MAN1=	mairix.1
MAN5=	mairixrc.5
PLIST_FILES=	bin/mairix %%EXAMPLESDIR%%/dotmairixrc.eg
PLIST_DIRS=	%%EXAMPLESDIR%%

OPTIONS_DEFINE=	GZIP BZIP
GZIP_DESC=	Enable gzip mbox support
BZIP_DESC=	Enable bzip2 mbox support

OPTIONS_DEFAULT=

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGZIP}
CONFIGURE_ARGS+=	--enable-gzip-mbox
.else
CONFIGURE_ARGS+=	--disable-gzip-mbox
.endif

.if ${PORT_OPTIONS:MBZIP}
CONFIGURE_ARGS+=	--enable-bzip-mbox
.else
CONFIGURE_ARGS+=	--disable-bzip-mbox
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mairix ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/mairix.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mairixrc.5 ${PREFIX}/man/man5

.include <bsd.port.mk>
