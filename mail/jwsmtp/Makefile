PORTNAME=	jwsmtp
PORTVERSION=	1.32.15
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/jwsmtp%20version%201.32.15%20bugfix/

MAINTAINER=	info@babaei.net
COMMENT=	C++ library for sending email

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_DESC=	Install documentation
MANPAGES_DESC=	Install manpages

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
