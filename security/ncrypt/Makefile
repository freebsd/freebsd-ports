PORTNAME=	ncrypt
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION:R}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced AES file encryption tool
WWW=		https://ncrypt.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=     Last release in 2015 and no active development since, consider using security/age
EXPIRATION_DATE=2024-03-31

USES=		tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ncrypt bin/nrm

post-patch:
	@${REINPLACE_CMD} -e \
		's|getopt.$$(OBJEXT) || ; \
		 s|getopt1.$$(OBJEXT) || ; \
		 s|getopt.c || ; \
		 s|getopt1.c ||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O0|| ; \
		 s|"\($$CCOPTS\)"|"\1 $$CFLAGS"|' ${WRKSRC}/configure

.include <bsd.port.mk>
