# Created by: ijliao
# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	src-
PORTREVISION=	4
CATEGORIES=	misc gnome
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	gnome-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive height field generation and manipulation program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/lib/libtrio.a:devel/trio

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		autoreconf gettext gmake pathfix pkgconfig tar:tgz
USE_GCC=	yes
USE_GNOME=	libgnomeprintui libgnomeui
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s| desktop-links docs | |' \
		 ${WRKSRC}/Makefile.am

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop-links/Terraform.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/desktop-links/terraform.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FAQ.sgml README.sgml UsersGuide.sgml i18n.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
