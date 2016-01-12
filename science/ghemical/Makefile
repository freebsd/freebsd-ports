# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	3.0.0
PORTREVISION=	8
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	release20111012 current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computational chemistry software package

LICENSE=	GPLv2+

LIB_DEPENDS=	libmopac7.so:${PORTSDIR}/biology/mopac \
		libghemical.so:${PORTSDIR}/science/libghemical \
		liboglappth.so:${PORTSDIR}/science/liboglappth \
		libmpqc.so:${PORTSDIR}/science/mpqc \
		libopenbabel.so:${PORTSDIR}/science/openbabel \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		fortran gettext gmake pathfix pkgconfig
USE_GNOME=	gtk20 libglade2 intltool
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk --enable-threads --enable-openbabel

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	GHEMICAL_VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|"mozilla "|"xdg-open "|' ${WRKSRC}/src/gtk_app.cpp

.include <bsd.port.mk>
