# New ports collection makefile for: gnomesword
# Date created:   Oct 26, 2002
# Whom:           J Shoemaker <shoemaker@softhome.net>
#
# $FreeBSD$
#

PORTNAME=	gnomesword
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword
RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

USE_X_PREFIX=  	yes
USE_GNOME=	gal gnomehack gnomeprefix gtkhtml
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DUSE_GTKHTML1" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
