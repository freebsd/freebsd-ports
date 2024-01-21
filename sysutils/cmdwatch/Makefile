PORTNAME=	cmdwatch
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.chruetertee.ch/files/download/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Watches the output from a command at specified intervals

LICENSE=	GPLv2+

USES=		ncurses
PLIST_FILES=	bin/cmdwatch share/man/man1/cmdwatch.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
