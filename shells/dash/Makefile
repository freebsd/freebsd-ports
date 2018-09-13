# $FreeBSD$

PORTNAME=	dash
PORTVERSION=	0.5.10.2
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	POSIX-compliant implementation of /bin/sh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
# SIGRTMAX is larger than NSIG*2 which mksignames.c does not support.  Just
# disable RT signal handling.
CFLAGS+=	-DUNUSABLE_RT_SIGNALS

USES=		gmake

PLIST_FILES=	bin/dash \
		man/man1/dash.1.gz

post-patch:
	${REINPLACE_CMD} -e '/COMMON_CFLAGS =/ s|$$| ${CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
