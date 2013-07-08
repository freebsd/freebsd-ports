# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	htmlise
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.ex-parrot.com/~chris/stuff/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Formats plain text as HTML

MAKE_JOBS_SAFE=	yes

TABSIZE?=	8

SRC=		htmlise tables markup inline
PLIST_FILES=	bin/htmlise

post-patch:
	@${REINPLACE_CMD} -e 's|\(TABSIZE\ \)[0-9]*|\1${TABSIZE}|' \
		${WRKSRC}/${PORTNAME}.h

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f}.c -o ${WRKSRC}/${f}.o
.endfor
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${SRC:C/(.*)/${WRKSRC}\/\1.o/}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
