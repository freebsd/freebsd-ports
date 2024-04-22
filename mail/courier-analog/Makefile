PORTNAME=	courier-analog
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/courier/analog/${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Courier log analyzer
WWW=		https://www.courier-mta.org/download.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

RUN_DEPENDS=	p5-Getopt-Long>0:devel/p5-Getopt-Long

USES=		tar:bz2 autoreconf perl5

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

NO_ARCH=	yes

PLIST_FILES=	bin/courier-analog \
		share/man/man8/courier-analog.8.gz

.include <bsd.port.mk>
