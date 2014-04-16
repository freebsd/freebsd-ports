# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssddiff
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1469/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Diff application for semistructured data such as XML files

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
USES=		pkgconfig
USE_GNOME=	libxml2 
USE_GCC=	any
USE_AUTOTOOLS=	automake14

PLIST_FILES=	bin/xmldiff

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

post-patch:
.for f in config.guess config.sub install-sh missing mkinstalldirs
	@${LN} -sf ${AUTOMAKE_DIR}/${f} ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS|AM_CPPFLAGS|' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e \
		's|"getopt\.h"|<unistd.h>|' ${WRKSRC}/src/main.cc

.include <bsd.port.mk>
