# Created by: ijliao
# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	src-
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive height field generation and manipulation program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/lib/libtrio.a:${PORTSDIR}/devel/trio

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		pathfix gettext gmake pkgconfig
USE_GCC=	yes
USE_GNOME=	gnomehier libgnomeprintui libgnomeui
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DOCS=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s| desktop-links docs | |' \
		 ${WRKSRC}/Makefile.in

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/depcomp ${WRKSRC}

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
