PORTNAME=	dmidecode
PORTVERSION=	3.4
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64 riscv64sf

USES=		tar:xz

SUB_FILES=	dmidecode

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# Additional programs are only built for x86 platforms.
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/dmidecode ${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.post.mk>
