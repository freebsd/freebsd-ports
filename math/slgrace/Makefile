PORTNAME=	slgrace
PORTVERSION=	0.2.2
PORTREVISION=	10
CATEGORIES=	math devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v${SLANG_VER}/modules/grace/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v${SLANG_VER}/modules/grace/ \
		LOCAL/garga/slgrace

MAINTAINER=	garga@FreeBSD.org
COMMENT=	SLang module to plot graphs with grace

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2
RUN_DEPENDS=	grace:math/grace

OPTIONS_DEFINE=	DOCS

SLANG_VER=	2.1

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's, install_docfiles,,' \
			  -e '/MKINSDIR.*DEST_DOC_FILES_INSTALL_DIR/d' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
