# $FreeBSD$

PORTNAME=	vmaf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.15
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Perceptual video quality assessment based on multi-method fusion

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 i386

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Netflix
MAKE_ARGS=	INSTALL_PREFIX="${PREFIX}"
CFLAGS_i386=	-msse # https://github.com/Netflix/vmaf/issues/374

post-patch:
	@${REINPLACE_CMD} -e '/^CC[[:>:]]/d' \
		-e '/FLAGS =/s/=/+=/' \
		-e 's/ -O[[:>:]]//; s/ -O[0-9]//; s/ -g//' \
		-e '/^CCFLAGS/s/$$/ $$(LDFLAGS)/' \
		${WRKSRC}/ptools/Makefile.VMAF \
		${WRKSRC}/*/Makefile

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wrapper/vmafossexec \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
