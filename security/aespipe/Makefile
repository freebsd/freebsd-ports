PORTNAME=	aespipe
PORTVERSION=	2.4e
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	http://loop-aes.sourceforge.net/${PORTNAME}/ \
		http://koti.tnnet.fi/jari.ruusu/linux/

MAINTAINER=	gehm@physik.tu-berlin.de
COMMENT=	AES encrypting or decrypting pipe

LICENSE=	GPLv2

RUN_DEPENDS=	gpg:security/gnupg

USES=		tar:bzip2
GNU_CONFIGURE=	yes
TEST_TARGET=	tests

PLIST_FILES=	bin/aespipe man/man1/aespipe.1.gz

OPTIONS_DEFINE_amd64=	ASM INTEL PADLOCK
OPTIONS_DEFINE_i386=	ASM INTEL PADLOCK

INTEL_DESC=		Support Intel hardware AES
PADLOCK_DESC=		Support VIA Padlock hardware AES

ASM_CONFIGURE_ENABLE=	asm=${ARCH:S/i386/x86/}

INTEL_CONFIGURE_ENABLE=	intelaes
INTEL_IMPLIES=		ASM

PADLOCK_CONFIGURE_ENABLE=	padlock
PADLOCK_IMPLIES=	ASM

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
