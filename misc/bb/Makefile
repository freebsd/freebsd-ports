PORTNAME=	bb
DISTVERSION=	1.3rc1
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	SF/aa-project/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality audio-visual demonstration for text terminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaa.so:graphics/aalib \
		libmikmod.so:audio/libmikmod

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
WRKSRC=		${WRKDIR}/bb-1.3.0
PORTDOCS=	README
PLIST_FILES=	bin/bb share/man/man1/bb.1.gz share/bb/bb.s3m share/bb/bb2.s3m \
		share/bb/bb3.s3m
CFLAGS+=	-Wno-error=implicit-int -Wno-pointer-sign

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
