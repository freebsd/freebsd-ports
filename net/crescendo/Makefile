# New ports collection makefile for:    crescendo
# Date created:         27.Apr 2000
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	crescendo
PORTVERSION=	1.1.7
CATEGORIES=	net gnome
# Master Site broken
#MASTER_SITES=	http://crescendo.lyrical.net/files/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org

RUN_DEPENDS=	tf:${PORTSDIR}/net/tinyfugue

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--enable-compile-warnings=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-g
PLIST_SUB=	DOCDIR=share/doc/${PORTNAME}

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(prefix\)/share/|\$\(datadir\)/|g'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog HACKING INSTALL NEWS \
		README README.BINARY TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
