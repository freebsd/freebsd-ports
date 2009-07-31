# New ports collection makefile for:	fpm
# Date created:				10 June 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	fpm
PORTVERSION=	0.60
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Figaro's Password Manager, an app to securely store your passwords

USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
#CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		fpm.1
PORTDOCS=	AUTHORS ChangeLog README TODO
PLIST_FILES=	bin/fpm share/pixmaps/fpm/logo.xpm
PLIST_DIRS=	share/pixmaps/fpm

pre-build:
	${REINPLACE_CMD} -E -e "s@encrypt\(@bfishencrypt\(@g" ${WRKSRC}/src/blowfish.c

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/fpm
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/fpm
.endfor
.endif
	@${ECHO} "========================================================================="
	@${ECHO} "Make sure you set up a few IRQ's for random generation with rndcontrol before"
	@${ECHO} "expecting password generation to work well."
	@${ECHO} "========================================================================="

.include <bsd.port.mk>
