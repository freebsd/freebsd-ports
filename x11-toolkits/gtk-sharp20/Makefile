# Created by: Juli Mallett
# $FreeBSD$

PORTNAME=	gtk-sharp
PORTVERSION=	2.12.10
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	20

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 libglade2
USES=		gmake libtool mono pathfix perl5 pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	parser/*.pl
USE_PERL5=	run
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/glib/glue/*.c

.include <bsd.port.mk>
