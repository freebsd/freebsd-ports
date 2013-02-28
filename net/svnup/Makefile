# $FreeBSD$

PORTNAME=	svnup
PORTVERSION=	0.55
CATEGORIES=	net
MASTER_SITES=	http://jcm.dsl.visi.com/freebsd/svnup/

MAINTAINER=	jcm@visi.com
COMMENT=	Lightweight program to pull source using the svn protocol

LICENSE=	BSD

LDFLAGS+=	-lmd
USE_XZ=	yes

MAN1=	${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC} && \
		${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
