PORTNAME=	grpn
PORTVERSION=	1.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-based reverse polish notation (RPN) calculator

LICENSE=	GPLv2

USES=		gnome pkgconfig
USE_GNOME=	gtk20
USE_GITHUB=	yes
GH_ACCOUNT=	utopiabound

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/grpn man/man1/grpn.1.gz
PORTDOCS=	CHANGES

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,ulong,unsigned long,g' \
		${WRKSRC}/real.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
