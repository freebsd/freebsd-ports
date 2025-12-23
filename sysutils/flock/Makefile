PORTNAME=	flock
PORTVERSION=	2.41.3
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${PORTVERSION:R}/
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Manage locks from shell scripts
WWW=		https://www.kernel.org/pub/linux/utils/util-linux/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-liblastlog2 --disable-nls

CFLAGS+=	-D_WITH_CPU_SET_T

PLIST_FILES=	bin/flock share/man/man1/flock.1.gz \
		etc/bash_completion.d/flock

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--disable-year2038
.endif

do-build:
	# skip building unneeded utils
	${MAKE} -C ${WRKSRC} flock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sys-utils/flock.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash-completion/flock ${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.mk>
