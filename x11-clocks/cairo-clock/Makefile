# New ports collection makefile for:   cairo-clock
# Date created:                2007/01/16
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	cairo-clock
PORTVERSION=	0.3.2
PORTREVISION=	3
CATEGORIES=	x11-clocks net gnome
MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	MacSlow's Cairo-Clock

USE_BZIP2=	yes
USE_GNOME=	gtk20 intlhack gnomehack libglade2 librsvg2
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
GZIP_CMD?=	/usr/bin/gzip
MAN1=		cairo-clock.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${GZIP_CMD} -d ${WRKSRC}/man/cairo-clock.1.gz
	@${REINPLACE_CMD} -e 's,.gz,,; s,datadir)\/man,prefix)\/man,' \
		${WRKSRC}/man/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README NEWS AUTHORS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${ECHO} ""
	@${ECHO} "************************************************************************"
	@${ECHO} " Please note that you need composite extension enabled in X.org or Xgl. "
	@${ECHO} "************************************************************************"

.include <bsd.port.mk>
