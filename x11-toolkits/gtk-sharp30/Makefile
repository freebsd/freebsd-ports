# Created by: Juli Mallett
# $FreeBSD$

PORTNAME=	gtk-sharp
PORTVERSION=	2.99.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk30
USES=		gmake libtool mono pathfix perl5 pkgconfig shebangfix tar:xz
SHEBANG_FILES=	parser/*.pl
USE_PERL5=	run
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

post-patch:
	@${REINPLACE_CMD} -e 's|gmcs|mcs|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
