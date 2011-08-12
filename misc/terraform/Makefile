# ex:ts=8
# Ports collection makefile for:	terraform
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terraform
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	src-
CATEGORIES=	misc gnome
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive height field generation and manipulation program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/lib/libtrio.a:${PORTSDIR}/devel/trio

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnomehack gnomehier libgnomeprintui libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s| desktop-links docs | |' \
		 ${WRKSRC}/Makefile.in

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/depcomp ${WRKSRC}

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/desktop-links/Terraform.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/desktop-links/terraform.png \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ.sgml README.sgml UsersGuide.sgml i18n.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
