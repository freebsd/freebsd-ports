# New ports collection makefile for:	GINI
# Date created:				23 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gini
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	net multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight media streaming server

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

MAN1=		ginicon.1 ginifeed.1
MAN8=		gini.8

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gini.sh.sample ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
