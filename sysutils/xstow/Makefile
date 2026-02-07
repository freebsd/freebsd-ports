PORTNAME=	xstow
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced replacement for GNU stow written in C++
WWW=		https://xstow.sourceforge.net/

LICENSE=	GPLv2

USES=		tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_FILES=	bin/merge-info bin/xstow \
		share/man/man1/merge-info.1.gz share/man/man1/xstow.1.gz \
		share/man/man5/xstow.ini.5.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO xstow.html \
		xstow.ini xstow.ini.html

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${INSTALL_DATA} ${PORTDOCS:M[ACNRT]*:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
