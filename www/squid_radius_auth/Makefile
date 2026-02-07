PORTNAME=	squid_radius_auth
PORTVERSION=	1.10
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/contrib/squid_radius_auth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RADIUS authenticator for squid proxy 2.5 and later
WWW=		http://www.squid-cache.org/contrib/squid_radius_auth

MAKE_ENV=	BINDIR=${PREFIX}/libexec/squid \
		CONFDIR=${PREFIX}/etc/squid \
		MANDIR=${PREFIX}/share/man/man8
ALL_TARGET=	ALL

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS|LDFLAGS)/s/=/?=/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E '/^(PREFIX|BINDIR|CONFDIR|MANDIR)/s/=/?=/' \
		${WRKSRC}/Make.inc

.include <bsd.port.mk>
