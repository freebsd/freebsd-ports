# Ports collection makefile for:	masqmail-devel
# Date created:				4 Apr 2004
# Whom:					Andrey Slusar <vasallia@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	masqmail
PORTVERSION=	0.2.20
CATEGORIES=	mail
MASTER_SITES=	http://innominate.org/kurth/masqmail/download/

MAINTAINER=	anray@inet.ua
COMMENT=	Mail server for hosts, not permanently connected to the internet

CONFLICTS=	masqmail-0.1*

MAN5=		masqmail.aliases.5 masqmail.conf.5 masqmail.get.5 masqmail.route.5
MAN8=		masqmail.8 mservdetect.8

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-trigraphs
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man --with-user=mailnull --with-group=mail \
		--with-confdir=${PREFIX}/etc/masqmail --with-logdir=/var/log/masqmail
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_LIBCRYPTO)
CONFIGURE_ARGS+=	--with-libcrypto
.endif
.if defined(WITHOUT_POP3)
CONFIGURE_ARGS+=	--disable-pop3
.endif
.if defined(WITHOUT_SMTP)
CONFIGURE_ARGS+=	--disable-smtp-server
.endif
.if defined(WITHOUT_RESOLVER)
CONFIGURE_ARGS+=	--disable-resolver
.endif
.if defined(WITH_MAILDIR)
CONFIGURE_ARGS+=	--enable-maildir
.endif
.if defined(WITH_MSERVER)
CONFIGURE_ARGS+=	--enable-mserver
.endif
.if defined(WITH_AUTH)
CONFIGURE_ARGS+=	--enable-auth
.endif
.if defined(WITH_IDENT)
CONFIGURE_ARGS+=	--enable-ident
.endif

USE_GNOME=	glib12
USE_RC_SUBR=	yes
NO_LATEST_LINK=	yes

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
	${FILESDIR}/masqmail.sh > ${WRKDIR}/masqmail.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/masqmail.sh ${PREFIX}/etc/rc.d/masqmail.sh
	${MKDIR} ${PREFIX}/etc/masqmail
	${CHOWN} mailnull:mail ${PREFIX}/etc/masqmail
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/masqmail.conf ${PREFIX}/etc/masqmail/masqmail.conf-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/example.get ${PREFIX}/etc/masqmail/masqmail.get-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/example.route ${PREFIX}/etc/masqmail/masqmail.route-dist

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in  AUTHORS COPYING INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
