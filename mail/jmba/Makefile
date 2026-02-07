PORTNAME=	jmba
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://codeberg.org/a-j-wood/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Junk Mail Buffering Agent
WWW=		https://www.ivarch.com/programs/jmba.shtml

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=	gmake tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ac_cv_func_gettext=no ac_cv_lib_intl_main=no

PLIST_FILES=	bin/jmba \
		share/man/man1/jmba.1.gz

.include <bsd.port.mk>
