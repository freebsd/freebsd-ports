# New ports collection makefile for:   samefile
# Date created:        15 March 2001
# Whom:                schweikh
#
# $FreeBSD$
#

PORTNAME=      samefile
PORTVERSION=   2.10
CATEGORIES=    sysutils
MASTER_SITES=  http://www.schweikhardt.net/

MAINTAINER=    schweikh@FreeBSD.org
COMMENT=	Find files with identical contents

MAN1=          samefile.1
PLIST_FILES=	bin/samefile
GNU_CONFIGURE= yes

CFLAGS+= -ansi -pedantic -Wall -Wshadow -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wconversion -Wsign-compare -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wmissing-noreturn -Wredundant-decls -Wnested-externs -Winline -Wno-long-long

post-build:
	@echo "   >>>>                        <<<<"
	@echo "   >>>> Running the test suite <<<<"
	@echo "   >>>>                        <<<<"
	cd ${WRKSRC}; ${MAKE} test

post-install:
	${STRIP_CMD} ${PREFIX}/bin/samefile

.include <bsd.port.mk>
