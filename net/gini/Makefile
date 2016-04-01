# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gini
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight media streaming server

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USES=		tar:bzip2 gmake
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		${PORTNAME}
GROUPS=		${USERS}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gini.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
