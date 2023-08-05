PORTNAME=	klish
PORTVERSION=	2.1.4
CATEGORIES=	shells
MASTER_SITES=	http://libcode.org/attachments/download/70/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Kommand Line Interface Shell
WWW=		http://libcode.org/projects/klish/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		libtool tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
