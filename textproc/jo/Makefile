PORTNAME=	jo
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/jpmens/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small utility to create JSON objects
WWW=		https://github.com/jpmens/jo

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/jo \
		etc/bash_completion.d/jo.bash \
		share/man/man1/jo.1.gz \
		share/zsh/site-functions/_jo

.include <bsd.port.mk>
