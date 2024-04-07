PORTNAME=	firestring
PORTVERSION=	0.9.12
PORTREVISION=	1
CATEGORIES=	misc net devel
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Library to make string handling easier in C
WWW=		https://www.firestuff.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

BROKEN=		Unfetchable
DEPRECATED=	Upstream is gone and last release in 2004
EXPIRATION_DATE=2024-04-30

USES=		tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MANDIR=${PREFIX}/share/man
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.mk>
