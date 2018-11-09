# $FreeBSD$

PORTNAME=	dhcpd
PORTVERSION=	6.4.20181105
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD dhcp daemon

LICENSE=	BSD3CLAUSE

USES=		ssl uidfix

WRKSRC_SUBDIR=	src/usr.sbin/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	koue

CONFLICTS=	isc-dhcp4[1-3]-server*

USE_RC_SUBR=	dhcpd

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

OPTIONS_DEFINE= NOPF

NOPF_DESC=	Disable PF support

OPTIONS_SUB=	yes

NOPF_CFLAGS=	-DNO_PF=1

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/dhcpd.conf|${PREFIX}/etc/dhcpd.conf|" \
		${WRKSRC}/dhcpd.[h8]

post-install:
	${INSTALL_DATA} ${WRKSRC}/dhcpd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpd.conf.sample

.include <bsd.port.mk>
