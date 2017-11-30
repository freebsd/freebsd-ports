# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rovclock
PORTVERSION=	0.6e
CATEGORIES=	sysutils
MASTER_SITES=	http://www.hasw.net/linux/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Overclocking utility for ATI Radeon video cards

LICENSE=	GPLv2

BROKEN_aarch64=		fails to install: undefined reference to outl
BROKEN_armv6=		fails to install: undefined reference to outl
BROKEN_armv7=		fails to install: undefined reference to outl
BROKEN_mips=		fails to install: undefined reference to outl
BROKEN_mips64=		fails to install: undefined reference to outl
BROKEN_powerpc64=	fails to install: undefined reference to outl

USES=		tar:bzip2

PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/${PORTNAME}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -Wall -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
