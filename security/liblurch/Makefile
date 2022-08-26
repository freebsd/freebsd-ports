PORTNAME=	liblurch
PORTVERSION=	0.7.0
DESCR=	
CATEGORIES=	security net-im net
MASTER_SITES=	https://github.com/gkdr/lurch/releases/download/v0.7.0/ 
#USE_GITHUB=	yes
#GH_ACCOUNT=	gkdr
#GH_PROJECT=	lurch
#GH_TAGNAME=	84f72d8

WRKSRC=		$(WRKDIR)/lurch-${PORTVERSION}
PKGDIR=         $(WRKDIR)/lurch-${PORTVERSION}
DISTNAME=       lurch-${PORTVERSION}-src
#DISTNAME=       ${PORTNAME}-${PORTVERSION}
MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Portable OMEMO Encryption Library

LICENSE=	GPLv2 # only

LIB_DEPENDS=	libmxml.so:textproc/mxml \
		libpurple.so:net-im/libpurple

#GNU_CONFIGURE=	no
USES=		gmake cpe libtool pathfix pkgconfig
#USE_LDCONFIG=	no
NO_CHECKSUM=	yes
NO_PACKAGE=	yes

do-install:
	${MKDIR}	/usr/home/${USER}/.purple/plugins/ 
	(cd ${WRKSRC}/build/ && cp ./lurch.so /usr/home/${USER}/.purple/plugins/)


CPE_VENDOR=	micadeyeye

.include <bsd.port.mk>
