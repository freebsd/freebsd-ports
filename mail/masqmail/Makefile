PORTNAME=	masqmail
DISTVERSION=	0.3.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://marmaro.de/prog/masqmail/files/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mail server for hosts, not permanently connected to the internet
WWW=		http://marmaro.de/prog/masqmail/

LICENSE=	GPLv2

DEPRECATED=	Unmaintained with known parser and memory-safety issues use dma from base or mail/msmtp
EXPIRATION_DATE=	2026-11-10

USES=		cpe gnome pkgconfig
CPE_VENDOR=	marmaro
USE_GNOME=	glib20
USE_RC_SUBR=	masqmail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=mailnull --with-group=mail \
		--with-confdir=${ETCDIR} --with-logdir=/var/log/masqmail

CFLAGS+=	-Wno-trigraphs

OPTIONS_DEFINE=	RESOLVER AUTH DEBUG DOCS
OPTIONS_DEFAULT=	RESOLVER AUTH

AUTH_DESC=	SMTP AUTH (RFC2554) support
RESOLVER_DESC=	Resolver

AUTH_CONFIGURE_ENABLE=	auth
DEBUG_CONFIGURE_ENABLE=	debug
RESOLVER_CONFIGURE_ENABLE=	resolver

post-patch:
	@${REINPLACE_CMD} -e '/sed.*SENDMAIL/ s|$$(DESTDIR)||' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/masqmail.conf ${STAGEDIR}${ETCDIR}/masqmail.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/example.route ${STAGEDIR}${ETCDIR}/masqmail.route.sample
	${INSTALL_DATA} ${WRKSRC}/examples/localnet.route ${STAGEDIR}${ETCDIR}/localnet.route.sample
	${INSTALL_DATA} ${WRKSRC}/examples/openssl.route ${STAGEDIR}${ETCDIR}/openssl.route.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	cd ${WRKSRC} && ${CP} ChangeLog NEWS AUTHORS COPYING README TODO INSTALL THANKS ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/docs/

.include <bsd.port.mk>
