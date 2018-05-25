# $FreeBSD$

PORTNAME=	dhcpd
PORTVERSION=	6.0.20170207
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD dhcp daemon

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src/usr.sbin/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	koue

CONFLICTS=	isc-dhcp4[1-3]-server*

USES=		ssl uidfix
USE_RC_SUBR=	dhcpd

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		dhcpd
GROUPS=		dhcpd

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/dhcpd.conf|${PREFIX}/etc/dhcpd.conf|" \
		${WRKSRC}/dhcpd.[h8]

post-install:
	${INSTALL_DATA} ${WRKSRC}/dhcpd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpd.conf.sample

.include <bsd.port.mk>
