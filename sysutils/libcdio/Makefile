# New ports collection makefile for:	libcdio
# Date created:				2004-04-04
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb \
		popt.0:${PORTSDIR}/devel/popt \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig gnomehack
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-libpopt-prefix=${LOCALBASE} \
			--with-libiconv-prefix=${LOCALBASE} \
USE_PERL5_BUILD=yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"
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
