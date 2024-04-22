PORTNAME=	fonteditfs
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	fnteditfs-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uri@keves.org
COMMENT=	Full screen syscons font editor
WWW=		https://fonteditfs.sourceforge.net/

USES=		ncurses
PLIST_FILES=	bin/fnteditfs share/man/man1/fnteditfs.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|__PREFIX__|${STAGEDIR}${PREFIX}|g ; \
		s|__INSTALL_MAN__|${INSTALL_MAN}|g ; \
		s|__INSTALL_SCRIPT__|${INSTALL_SCRIPT}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
