PORTNAME=	bbe
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}-/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sed-like editor for binary files
WWW=		https://sourceforge.net/projects/bbe-/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbe.html ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
