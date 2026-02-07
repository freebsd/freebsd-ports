PORTNAME=	clean
DISTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Automatically remove unwanted files
WWW=		https://sourceforge.net/projects/clean/

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	Permission is granted to copy, modify, and use this as long as this message remains intact.
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		tar:bzip2

PLIST_FILES=	bin/clean \
		share/man/man1/clean.1.gz

post-patch:
	@${REINPLACE_CMD} 's|$$(PREFIX)|$$(DESTDIR)$$(PREFIX)| ; \
		s|man/man1|share/man/man1|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
