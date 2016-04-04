# Created by: Chad Castleberry AKA ritalin
# $FreeBSD$

PORTNAME=	rename
PORTVERSION=	1.99.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename multiple files using regular expressions

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/renamex man/man1/renamex.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s|\([[:blank:]]\)\(=\)|\1?\2| ; \
		 /^PREFIX/s|\([[:blank:]]\)\(=\)|\1?\2| ; \
		 s|/usr/local/bin|$$(PREFIX)/bin| ; \
		 s|/usr/local/man|$$(PREFIX)/man| ; \
		 /^CFLAGS/s|\([[:blank:]]\)\(=\)|\1+\2| ; \
		 s|-O[0-9]|| ; \
		 s|$$^$$|$$(OBJS)| ; \
		 /cp/s|^|#| ; \
		 s|install .* 0755 -s|$${BSD_INSTALL_PROGRAM}| ; \
		 s|\([[:blank:]]\)\($$(BINDIR)\)|\1$$(DESTDIR)\2| ; \
		 s|install .* 0644|$${BSD_INSTALL_MAN}| ; \
		 s|\([[:blank:]]\)\($$(MANDIR)\)|\1$$(DESTDIR)\2| ; \
		 s|^%.*|.c.o:|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
