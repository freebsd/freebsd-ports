PORTNAME=	libxls
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Extract Cell Data From Excel xls files
WWW=		https://github.com/libxls/libxls

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lang cpe libtool
CPE_VENDOR=	${PORTNAME}_project

CONFLICTS_INSTALL=	catdoc p5-Spreadsheet-Read xls2txt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
