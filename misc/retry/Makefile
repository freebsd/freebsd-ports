PORTNAME=	retry
DISTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/minfrin/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	jon@zikomo.xyz
COMMENT=	Retry a command until the command succeeds
WWW=		https://github.com/minfrin/retry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/retry \
		share/man/man1/retry.1.gz

.include <bsd.port.mk>
