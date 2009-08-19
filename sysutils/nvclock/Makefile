# New ports collection makefile for:	NVClock
# Date created:				August 4, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	nvclock
DISTVERSION=	0.8b4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	nvclock${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The NVidia graphic card status and overclocking tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	aclocal:19 autoheader:262 autoconf:262

PLIST_FILES=	bin/nvclock \
		bin/smartdimmer
MAN1=		nvclock.1
PORTDOCS=	ABOUT AUTHORS ChangeLog FAQ README

OPTIONS=	GUI	"Build with GTK user interface"		on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=--enable-gtk=no --enable-qt=no --enable-nvcontrol=no
.else
USE_XORG=	xext
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/nvclock_gtk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DISTDIR)||' ${WRKSRC}/src/Makefile.in

do-install:
	${GMAKE} -C ${WRKSRC}/src install
	${GMAKE} -C ${WRKSRC} install-man
.if !defined(WITHOUT_GUI)
	${GMAKE} -C ${WRKSRC}/src/gtk install
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${GMAKE} -C ${WRKSRC} install-docs
.endif

.include <bsd.port.post.mk>
