# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssddiff
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		http://ftp.is.co.za/FreeBSD/ports/distfiles/ \
		ftp://ftp.rediris.es/sites/ftp.freebsd.org/pub/FreeBSD/ports/distfiles/ \
		http://ftp.nchc.org.tw/BSD/FreeBSD/ports/distfiles/ \
		ftp://ftp.eunet.cz/FreeBSD/ports/distfiles/ \
		https://alioth.debian.org/frs/download.php/file/1469/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Diff application for semistructured data such as XML files

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
USES=		autoreconf gnome pkgconfig tar:bzip2
USE_GNOME=	libxml2

PLIST_FILES=	bin/xmldiff

post-patch:
	@${FIND} ${WRKSRC} -type l -delete
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS|AM_CPPFLAGS|' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e \
		's|"getopt\.h"|<unistd.h>|' ${WRKSRC}/src/main.cc
	@${REINPLACE_CMD} \
		-e 's/hash</__gnu_cxx::&/' -e 's/hash<char/& const/' \
		${WRKSRC}/src/doc.h ${WRKSRC}/src/out_common.cc \
		${WRKSRC}/src/out_merged.cc ${WRKSRC}/src/out_xupdate.cc \
		${WRKSRC}/src/out_xupdate.h ${WRKSRC}/src/ustring.cc \
		${WRKSRC}/src/ustring.h

.include <bsd.port.mk>
