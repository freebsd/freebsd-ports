# New ports collection makefile for:	gtktalog
# Date created:				20 Mar 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gtktalog
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to make disk catalogs

BUILD_DEPENDS=	plaympeg:${PORTSDIR}/multimedia/smpeg
RUN_DEPENDS=	plaympeg:${PORTSDIR}/multimedia/smpeg

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtktalog.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS BUGS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
