PORTNAME=	xspread
PORTVERSION=	3.1.1c
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://archive.debian.org/%SUBDIR%/ \
		http://mirror.safehostnet.com/debian-archive/%SUBDIR%/ \
		http://mirrors.xmission.com/debian-archive/%SUBDIR%/ \
		http://vos-systems.net/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	debian/dists/potato/main/source/math
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spreadsheet program for X and terminals

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GNU_GENERAL

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

GNU_CONFIGURE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/pxspread bin/xspread \
		share/man/man1/pxspread.1.gz \
		share/man/man1/xspread.1.gz

OPTIONS_DEFINE=	X11 DOCS

X11_USE=		XORG=x11,xau,xcb,xdmcp,xt
X11_USES=		localbase xorg
X11_CONFIGURE_ENV_OFF=	ac_cv_header_X11_X_h=no

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/lib/libXt|${LOCALBASE}/lib/libXt|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/psc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxspread ${STAGEDIR}${PREFIX}/bin/pxspread
	${INSTALL_PROGRAM} ${WRKSRC}/xspread ${STAGEDIR}${PREFIX}/bin/xspread
	${INSTALL_MAN} ${WRKSRC}/pxspread.man ${STAGEDIR}${PREFIX}/share/man/man1/pxspread.1
	${INSTALL_MAN} ${WRKSRC}/xspread.man ${STAGEDIR}${PREFIX}/share/man/man1/xspread.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x/notes ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc documents sample_files tests" ${STAGEDIR}${DOCSDIR} "! -name *.tmp")

.include <bsd.port.mk>
