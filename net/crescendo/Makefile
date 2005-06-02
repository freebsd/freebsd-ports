# New ports collection makefile for:    crescendo
# Date created:         27.Apr 2000
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	crescendo
PORTVERSION=	1.1.7
PORTREVISION=	2
CATEGORIES=	net gnome
# Master Site broken
#MASTER_SITES=	http://crescendo.lyrical.net/files/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gnome frontend for tinyfuge

RUN_DEPENDS=	tf:${PORTSDIR}/net/tinyfugue

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS+=	--enable-compile-warnings=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-g
PLIST_SUB=	DOCDIR=share/doc/${PORTNAME}
MODIFY=		Makefile.in data/Makefile.in

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

pre-patch:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e 's=$$(prefix)/share/=$$(datadir)/gnome/=g' \
		${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog HACKING INSTALL NEWS \
		README README.BINARY TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
