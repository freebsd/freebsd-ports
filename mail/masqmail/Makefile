# Ports collection makefile for:	masqmail
# Date created:				4 Apr 2004
# Whom:					Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	masqmail
PORTVERSION=	0.3.4
CATEGORIES=	mail
MASTER_SITES=	http://marmaro.de/prog/masqmail/files/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Mail server for hosts, not permanently connected to the internet

.if !defined (NO_INSTALL_MANPAGES)
MAN1=		mservdetect.1
MAN5=		masqmail.aliases.5 masqmail.conf.5 masqmail.route.5
MAN8=		masqmail.8 rmail.8
.endif

USE_GNOME=	glib20
USE_RC_SUBR=	masqmail
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-trigraphs
CONFIGURE_ARGS+=	--with-user=mailnull --with-group=mail \
		--with-confdir=${PREFIX}/etc/masqmail --with-logdir=/var/log/masqmail

OPTIONS +=	RESOLVER	"Resolver"		on
OPTIONS +=	AUTH		"SMTP AUTH (RFC2554) support"	on
OPTIONS +=	DEBUG		"Enable Debugging"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_RESOLVER)
CONFIGURE_ARGS+=	--disable-resolver
.endif
.if defined(WITH_AUTH)
CONFIGURE_ARGS+=	--enable-auth
.endif
.if defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--disable-debug
.endif

post-install:
	${CHOWN} mailnull:mail ${PREFIX}/etc/masqmail
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/masqmail.conf ${PREFIX}/etc/masqmail/masqmail.conf-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/example.route ${PREFIX}/etc/masqmail/masqmail.route-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/localnet.route ${PREFIX}/etc/masqmail/localnet.route-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/openssl.route ${PREFIX}/etc/masqmail/openssl.route-dist

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/docs
	cd ${WRKSRC} && ${CP} ChangeLog NEWS AUTHORS COPYING README TODO INSTALL THANKS ${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/docs/)
.endif

.include <bsd.port.post.mk>
