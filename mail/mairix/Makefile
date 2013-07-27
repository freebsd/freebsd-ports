# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mairix
PORTVERSION=	0.22
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Indexing and searching in Maildir, MH, or mbox folders

LICENSE=	GPLv2

USES=		bison gmake
HAS_CONFIGURE=	yes

MAN1=		mairix.1
MAN5=		mairixrc.5
PORTDOCS=	NEWS README
PORTEXAMPLES=	dotmairixrc.eg
PLIST_FILES=	bin/mairix

OPTIONS_DEFINE=	GZIP BZIP2 EXAMPLES DOCS
GZIP_DESC=	gzip compressed mbox support
BZIP2_DESC=	bzip2 compressed mbox support

GZIP_CONFIGURE_ENABLE=	gzip-mbox
BZIP2_CONFIGURE_ENABLE=	bzip-mbox

.include <bsd.port.options.mk>

# Do not hardcode make(1) binary name and fix atomicity to allow -jX builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+) ; make|$$(MAKE) -C \1|' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mairix ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mairix.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mairixrc.5 ${MANPREFIX}/man/man5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
