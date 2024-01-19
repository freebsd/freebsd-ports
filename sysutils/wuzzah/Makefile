PORTNAME=	wuzzah
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility for stalking users
WWW=		https://www.cs.swarthmore.edu/~finney/proj/wuzzah/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/wuzzah share/man/man1/wuzzah.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' -e 's|^\(SUBDIRS.*\)utmpx|\1|p' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
