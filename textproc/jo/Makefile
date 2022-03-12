PORTNAME=	jo
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/jpmens/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Small utility to create JSON objects

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/jo \
		etc/bash_completion.d/jo.bash \
		man/man1/jo.1.gz \
		share/zsh/site-functions/_jo

.include <bsd.port.mk>
