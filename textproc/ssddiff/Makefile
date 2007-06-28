# New ports collection makefile for:	SSDDiff
# Date created:				11 Apr 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssddiff
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1469/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A diff application for semistructured data such as XML files

USE_AUTOTOOLS=	automake:14
USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GNOME=	libxml2
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libxml2"
PLIST_FILES=	bin/xmldiff

post-extract:
.for f in config.guess config.sub install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/${f} ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's,"getopt\.h",<unistd.h>,' \
		${WRKSRC}/src/main.cc

.include <bsd.port.mk>
