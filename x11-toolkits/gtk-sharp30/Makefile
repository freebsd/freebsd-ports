PORTNAME=	gtk-sharp
PORTVERSION=	2.99.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USES=		gettext-runtime gmake gnome libtool mono pathfix perl5 \
		pkgconfig shebangfix tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
SHEBANG_FILES=	parser/*.pl
USE_PERL5=	run
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: 'Range' is an ambiguous reference between 'System.Range' and 'Gtk.Range'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gmcs|mcs|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
