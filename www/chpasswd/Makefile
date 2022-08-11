PORTNAME=	chpasswd
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	www
#MASTER_SITES=	SF/orsochpasswd/orsochpasswd/chpasswd-2.2.4/
MASTER_SITES=	SF/orso${PORTNAME}/orso${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Allow users to change their Squid or Web password using the browser

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/chpasswd \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin

.include <bsd.port.mk>
