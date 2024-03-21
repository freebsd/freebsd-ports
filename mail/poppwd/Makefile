PORTNAME=	poppwd
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ugh.net.au/pub/unix/poppwd/	\
		http://www.ugh.eclipse.co.uk/mirror/ftp.ugh.net.au/pub/unix/poppwd/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Implementation of the Eudora password changing protocol

WRKSRC=		${WRKDIR}/poppwd
USES=		uidfix

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	libexec/poppwd \
		share/man/man8/poppwd.8.gz

.include <bsd.port.mk>
