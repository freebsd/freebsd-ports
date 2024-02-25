PORTNAME=	pamtester
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line pam authentication tester
WWW=		https://pamtester.sourceforge.net/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	${CFLAGS}
USES=	gmake

PLIST_FILES=	bin/pamtester \
		share/man/man1/pamtester.1.gz

.include <bsd.port.mk>
