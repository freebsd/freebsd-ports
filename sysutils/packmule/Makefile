# Created by: Austin Shafer <ashafer@badland.io>
# $FreeBSD$

PORTNAME=	packmule
DISTVERSIONPREFIX=v
DISTVERSION=	1.1
CATEGORIES=	sysutils perl5

MAINTAINER=	ashafer@badland.io
COMMENT=	Creates and packs custom FreeBSD installation images

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

ONLY_FOR_ARCHS=	amd64 i386 powerpc

RUN_DEPENDS=	p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_GITHUB=	yes
USE_PERL5=	run

GH_ACCOUNT=	ashaferian
GH_PROJECT=	Packmule

NO_BUILD=	yes

# Create the packmule directory to hold arch dependent scripts,
# then install packmule, its manpage, and the image scripts
do-install:
# Make directories for the image generation scrips. They are
# taken from the FreeBSD sources.
	${MKDIR} \
	${STAGEDIR}${PREFIX}/packmule/mkiso/amd64 \
	${STAGEDIR}${PREFIX}/packmule/mkiso/i386 \
	${STAGEDIR}${PREFIX}/packmule/mkiso/powerpc \
	${STAGEDIR}${PREFIX}/packmule/make-memstick/amd64 \
	${STAGEDIR}${PREFIX}/packmule/make-memstick/i386 \
	${STAGEDIR}${PREFIX}/packmule/make-memstick/powerpc

# Install the perl script and its manpage
	${INSTALL_SCRIPT} ${WRKSRC}/packmule ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/packmule.1 \
		${STAGEDIR}${PREFIX}/man/man1

# Install scripts for generating iso images
	${INSTALL_SCRIPT} ${WRKSRC}/mkiso/amd64/mkisoimages.sh \
		${STAGEDIR}${PREFIX}/packmule/mkiso/amd64
	${INSTALL_SCRIPT} ${WRKSRC}/mkiso/i386/mkisoimages.sh \
		${STAGEDIR}${PREFIX}/packmule/mkiso/i386
	${INSTALL_SCRIPT} ${WRKSRC}/mkiso/powerpc/mkisoimages.sh \
		${STAGEDIR}${PREFIX}/packmule/mkiso/powerpc

# Install scripts for generating memstick images
	${INSTALL_SCRIPT} \
		${WRKSRC}/make-memstick/amd64/make-memstick.sh \
		${STAGEDIR}${PREFIX}/packmule/make-memstick/amd64
	${INSTALL_SCRIPT} \
		${WRKSRC}/make-memstick/i386/make-memstick.sh \
		${STAGEDIR}${PREFIX}/packmule/make-memstick/i386
	${INSTALL_SCRIPT} \
		${WRKSRC}/make-memstick/powerpc/make-memstick.sh \
		${STAGEDIR}${PREFIX}/packmule/make-memstick/powerpc

.include <bsd.port.mk>
