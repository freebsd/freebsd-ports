# $FreeBSD$

PORTNAME=	courier-analog
PORTVERSION=	0.17
CATEGORIES=	mail
MASTER_SITES=	SF/courier/analog/${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Courier log analyzer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

RUN_DEPENDS=	p5-Getopt-Long>0:devel/p5-Getopt-Long

USES=		tar:bz2 autoreconf perl5
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/courier-analog \
		man/man8/courier-analog.8.gz

.include <bsd.port.mk>
