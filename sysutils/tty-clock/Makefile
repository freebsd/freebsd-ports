# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	tty-clock
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal based clock

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	xorg62
GH_TAGNAME=	a82fd71

USES=		ncurses
ALL_TARGET=	tty-clock

PLIST_FILES=	bin/tty-clock

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 s|/usr/local|$${PREFIX}| ; \
		 /^CFLAGS/s| =| +=| ; \
		 s|-Wall -g|-Wall| ; \
		 /^LDFLAGS/s| =| +=| ; \
		 /@echo /s|^|#| ; \
		 s|@$${CC} |$${CC} | ; \
		 s|@cp |$${BSD_INSTALL_PROGRAM} | ; \
		 s| $${INSTALLPATH}| $${DESTDIR}$${INSTALLPATH}| ; \
		 /@chmod /s|^|#|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
