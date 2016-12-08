# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gini
PORTVERSION=	0.5.1
PORTREVISION=	9
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight media streaming server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		gmake localbase tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib12

USERS=		${PORTNAME}
GROUPS=		${USERS}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gini.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
