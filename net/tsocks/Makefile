# New ports collection makefile for:	tsocks
# Date created:				5th September 2003
# Whom:					Marcin Jessa <freebsd@yazzy.org>
#
# $FreeBSD$

PORTNAME=	tsocks
PORTVERSION=	1.8.b5
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://ftp1.sourceforge.net/tsocks/ \
		http://www.yazzy.org/ports/tsocks/
MASTER_SITE_SUBDIR=	tsocks
DISTNAME=${PORTNAME}-${PORTVERSION:C/.b/beta/}

MAINTAINER=	yazzy@yazzy.org
COMMENT=	Allow non SOCKS aware applications to use SOCKS without modification

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

WRKSRC=${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.b.*//}

CONFIGURE_ARGS=	--with-conf=${PREFIX}/etc/tsocks.conf \
		--libdir=${PREFIX}/lib

MAN1=		tsocks.1
MAN5=		tsocks.conf.5
MAN8=		tsocks.8

.if defined(WITH_SOCKSDNS)
CONFIGURE_ARGS+=	--enable-socksdns
.endif

.if defined(WITH_OLDMETHOD)
CONFIGURE_ARGS+=	--enable-oldmethod
.endif

.if defined(WITH_NODEBUG)
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(WITH_NOHOSTNAMES)
CONFIGURE_ARGS+=	--disable-hostnames
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_SOCKSDNS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the WITH_SOCKSDNS=yes knob."
	@${ECHO_MSG} "This option causes tsocks to intercept"
	@${ECHO_MSG} "DNS lookups and attempt to force them"
	@${ECHO_MSG} "to use TCP instead of UDP and thus"
	@${ECHO_MSG} "be proxied through the socks server."
	@${ECHO_MSG}
.endif

.if !defined(WITH_OLDMETHOD)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the make WITH_OLDMETHOD=yes knob."
	@${ECHO_MSG} "This forces tsocks not to use the"
	@${ECHO_MSG} "RTLD_NEXT parameter to dlsym to get the"
	@${ECHO_MSG} "address of the connect() method tsocks"
	@${ECHO_MSG} "overrides, instead it loads a reference"
	@${ECHO_MSG} "to the libc shared library and then uses dlsym()."
	@${ECHO_MSG}
.endif

.if !defined(WITH_NODEBUG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the make WITH_NODEBUG=yes knob."
	@${ECHO_MSG} "This configuration option tells tsocks"
	@${ECHO_MSG} "to never output error messages to stderr."
	@${ECHO_MSG}
.endif

.if !defined(WITH_NOHOSTNAMES)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the make WITH_NOHOSTNAMES=yes knob."
	@${ECHO_MSG} "This disables DNS lookups on names"
	@${ECHO_MSG} "provided as socks servers in the config"
	@${ECHO_MSG} "file. This option is necessary"
	@${ECHO_MSG} "if socks dns is enabled since tsocks"
	@${ECHO_MSG} "can't send a socks dns request to resolve"
	@${ECHO_MSG} "the location of the socks server."
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ufds|fds|g' ${WRKSRC}/tsocks.c
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/tsocks

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/examples/tsocks
	${INSTALL_DATA} ${WRKSRC}/*.example ${PREFIX}/share/examples/tsocks
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.simple.example ${PREFIX}/etc/tsocks.conf.sample
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/examples/tsocks/README
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
