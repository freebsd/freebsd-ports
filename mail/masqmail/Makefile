# Ports collection makefile for:	masqmail
# Date created:				4 Apr 2004
# Whom:					Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	masqmail
PORTVERSION=	0.2.21
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Mail server for hosts, not permanently connected to the internet

.if !defined (NO_INSTALL_MANPAGES)
MAN5=		masqmail.aliases.5 masqmail.conf.5 masqmail.get.5 masqmail.route.5
MAN8=		masqmail.8 mservdetect.8
.endif

USE_GNOME=	glib20
USE_RC_SUBR=	masqmail
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-trigraphs
CONFIGURE_ARGS+=	--with-user=mailnull --with-group=mail \
		--with-confdir=${PREFIX}/etc/masqmail --with-logdir=/var/log/masqmail
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined (NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README TODO
.endif

OPTIONS +=	LIBCRYPTO	"Use libcrypto"		on
OPTIONS +=	POP3		"Enable POP3"		on
OPTIONS +=	SMTP		"Enable SMTP server"	on
OPTIONS +=	Resolver	"Resolver"		on
OPTIONS +=	MAILDIR		"Maildir support"	on
OPTIONS	+=	MSERVER		"Enable mserver support"	off
OPTIONS +=	AUTH		"SMTP AUTH (RFC2554) support"	on
OPTIONS +=	IDENT		"Ident (RFC 1413) support"	off

.include <bsd.port.pre.mk>

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

post-install:
	${MKDIR} ${PREFIX}/etc/masqmail
	${CHOWN} mailnull:mail ${PREFIX}/etc/masqmail
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/masqmail.conf ${PREFIX}/etc/masqmail/masqmail.conf-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/example.get ${PREFIX}/etc/masqmail/masqmail.get-dist
	${INSTALL_DATA} -o mailnull -g mail ${WRKSRC}/examples/example.route ${PREFIX}/etc/masqmail/masqmail.route-dist

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
