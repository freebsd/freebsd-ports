PORTNAME=	smi
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	textproc www
MASTER_SITES=	https://BSDforge.com/projects/source/textproc/${PORTNAME}/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Simple Markdown Interpreter / filter for simplified markup dialect
WWW=		https://BSDforge.com/projects/textproc/smi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	README.md

PLIST_FILES=	bin/smi share/man/man1/smi.1.gz

USES=		tar:xz uidfix
MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ENV=	PROG="${PORTNAME}" FILES="${PORTDOCS}" \
		BINDIR="${PREFIX}/bin" FILESDIR="${DOCSDIR}" \
		MANDIR="${PREFIX}/share/man/man"
CFLAGS+=	-DVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

pre-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
