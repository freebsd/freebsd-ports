# Created by: arved
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.83
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig iconv ncurses
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
USE_PERL5_BUILD=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAN1=	cd-drive.1 cd-info.1 iso-read.1 iso-info.1 cd-read.1

INFO=		libcdio

.include <bsd.port.pre.mk>

_MANLANG=	"" ja
_MAN1=	cd-paranoia.1
.for lang in ${_MANLANG}
_MANPAGES+=	${_MAN1:S%^%${MAN1PREFIX}/man/${lang}/man1/%}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|/jp/man1|/ja/man1|' \
		${WRKSRC}/src/cd-paranoia/doc/ja/Makefile.in
	${REINPLACE_CMD} -e "s,freebsd5\.\*,freebsd*," ${WRKSRC}/configure

.include <bsd.port.post.mk>
