# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mairix
DISTVERSION=	0.24
CATEGORIES=	mail

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Indexing and searching in Maildir, MH, or mbox folders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to build under emulation: qemu: uncaught target signal 11 (Segmentation fault) - core dumped
BROKEN_armv7=	fails to build under emulation: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

USES=		bison gmake ssl
HAS_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	vandry

PLIST_FILES=	bin/mairix \
		man/man1/mairix.1.gz \
		man/man5/mairixrc.5.gz

OPTIONS_DEFINE=	GZIP BZIP2 EXAMPLES DOCS
GZIP_DESC=	gzip compressed mbox support
BZIP2_DESC=	bzip2 compressed mbox support

GZIP_CONFIGURE_ENABLE=	gzip-mbox
BZIP2_CONFIGURE_ENABLE=	bzip-mbox

PORTDOCS=	NEWS README
PORTEXAMPLES=	dotmairixrc.eg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mairix
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
