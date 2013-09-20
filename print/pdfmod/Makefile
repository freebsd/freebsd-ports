# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	pdfmod
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A tool for modifying PDF documents

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/hyena.pc:${PORTSDIR}/devel/hyena
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/hyena.pc:${PORTSDIR}/devel/hyena

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomesharp20
USES=		gettext
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
