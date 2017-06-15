# $FreeBSD$

PORTNAME=	dash
PORTVERSION=	0.5.8
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	POSIX-compliant implementation of /bin/sh

GNU_CONFIGURE=	yes
# This work in 11-CURRENT r266677M amd64 but fails to work in 11.0-CURRENT r266677 i386
CFLAGS+=	-DUNUSABLE_RT_SIGNALS

USES=		gmake

PLIST_FILES=	bin/dash man/man1/dash.1.gz

post-patch:
	${REINPLACE_CMD} -e '/COMMON_CFLAGS =/ s|$$| ${CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
