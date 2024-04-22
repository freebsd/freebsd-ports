PORTNAME=	msdl
PORTVERSION=	1.2.7r2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-r/}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Streaming multimedia files downloader
WWW=		https://msdl.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
PLIST_FILES=	bin/msdl \
		share/man/man1/msdl.1.gz

# Fix build with clang11
CFLAGS+=	-fcommon

.include <bsd.port.mk>
