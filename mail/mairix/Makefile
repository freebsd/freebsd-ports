# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mairix
PORTVERSION=	0.23
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Indexing and searching in Maildir, MH, or mbox folders

LICENSE=	GPLv2

BROKEN_armv6=		fails to build under emulation: qemu: uncaught target signal 11 (Segmentation fault) - core dumped
BROKEN_armv7=		fails to build under emulation: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

USES=		bison gmake
HAS_CONFIGURE=	yes

PORTDOCS=	NEWS README
PORTEXAMPLES=	dotmairixrc.eg
PLIST_FILES=	bin/mairix \
		man/man1/mairix.1.gz \
		man/man5/mairixrc.5.gz

OPTIONS_DEFINE=	GZIP BZIP2 EXAMPLES DOCS
GZIP_DESC=	gzip compressed mbox support
BZIP2_DESC=	bzip2 compressed mbox support

GZIP_CONFIGURE_ENABLE=	gzip-mbox
BZIP2_CONFIGURE_ENABLE=	bzip-mbox

# Do not hardcode make(1) binary name
post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+) ; make|$$(MAKE) -C \1|' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mairix ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mairix.1 ${STAGEDIR}/${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mairixrc.5 ${STAGEDIR}/${MANPREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
