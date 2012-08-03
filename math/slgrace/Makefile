# New ports collection makefile for:	slgrace
# Date created:		2007-08-30
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	slgrace
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	math devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v${SLANG_VER}/modules/grace/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v${SLANG_VER}/modules/grace/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/slgrace/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang module to plot graphs with grace

LIB_DEPENDS=	slang:${PORTSDIR}/devel/libslang2
RUN_DEPENDS=	grace:${PORTSDIR}/math/grace

OPTIONS_DEFINE=	DOCS

SLANG_VER=	2.1

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	*
PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's, install_docfiles,,' \
			  -e '/MKINSDIR.*DEST_DOC_FILES_INSTALL_DIR/d' \
		${WRKSRC}/src/Makefile.in
.else
	@${REINPLACE_CMD} -E 's,^(DOC_FILES_INSTALL_DIR) *= *.*$$,\1 = ${DOCSDIR},' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
