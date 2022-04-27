# Created by: Ed Schouten <ed@fxq.nl>

PORTNAME=	kissd
PORTVERSION=	0.3
CATEGORIES=	net multimedia
MASTER_SITES=	http://rink.nu/downloads/projects/

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Daemon for providing multimedia files to KiSS DP-50x players

DEPRECATED=	Obsolete, target hardware was released 19 years ago
EXPIRATION_DATE=2022-06-30

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/kissd

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/ s|-Werror||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
