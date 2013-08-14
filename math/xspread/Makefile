# Created by: janek@gaja.ipan.lublin.pl
# $FreeBSD$

PORTNAME=	xspread
PORTVERSION=	3.1.1c
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://archive.debian.org/%SUBDIR%/ \
		http://mirror.safehostnet.com/debian-archive/%SUBDIR%/ \
		http://mirrors.xmission.com/debian-archive/%SUBDIR%/ \
		http://vos-systems.net/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	debian/dists/potato/main/source/math
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spreadsheet program for X and terminals

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	X11 DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

GNU_CONFIGURE=	yes

MAN1=		xspread.1 pxspread.1
PORTDOCS=	*
PLIST_FILES=	bin/pxspread bin/xspread

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xau xcb xdmcp xt
LIB_DEPENDS+=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ENV+=	ac_cv_header_X11_X_h=no
.endif

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/lib/libXt|${LOCALBASE}/lib/libXt|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/psc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxspread ${PREFIX}/bin/pxspread
	${INSTALL_PROGRAM} ${WRKSRC}/xspread ${PREFIX}/bin/xspread
	${INSTALL_MAN} ${WRKSRC}/pxspread.man ${MANPREFIX}/man/man1/pxspread.1
	${INSTALL_MAN} ${WRKSRC}/xspread.man ${MANPREFIX}/man/man1/xspread.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x/notes ${DOCSDIR}
.for dir in doc documents sample_files tests
	@${TAR} -C ${WRKSRC} --exclude '*.tmp' -cf - ${dir} | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
