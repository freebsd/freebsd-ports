# New ports collection makefile for:	textproc/sagasu
# Date created:				10 Jul 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	sagasu
PORTVERSION=	2.0.10
CATEGORIES=	textproc gnome
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME tool to find strings in a set of files

USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		sagasu.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS INSTALL NEWS README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
