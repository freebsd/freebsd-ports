# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	firestring
PORTVERSION=	0.9.12
CATEGORIES=	misc net devel
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Library to make string handling easier in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		tar:bzip2
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.mk>
