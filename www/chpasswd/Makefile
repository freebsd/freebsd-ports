PORTNAME=	chpasswd
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/orso${PORTNAME}/orso${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Allow users to change their Squid or Web password using the browser
WWW=		https://sourceforge.net/projects/orsochpasswd/

LICENSE=	GPL-2.0-or-later
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-cgidir=${PREFIX}/www/cgi-bin \
		--enable-language=English \
		--prefix=${PREFIX}/etc/chpasswd

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin

.include <bsd.port.mk>
