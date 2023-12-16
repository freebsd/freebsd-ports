PORTNAME=	dhcpd
PORTVERSION=	6.6.20200413
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD dhcp daemon
WWW=		https://github.com/koue/dhcpd

LICENSE=	BSD3CLAUSE

USES=		ssl uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	koue
USE_RC_SUBR=	dhcpd

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

CFLAGS+=	-Wall

CONFLICTS=	isc-dhcp4[1-3]-server*
WRKSRC_SUBDIR=	src/usr.sbin/${PORTNAME}

OPTIONS_DEFINE=	NOPF
OPTIONS_SUB=	yes

NOPF_DESC=	Disable PF support

NOPF_CFLAGS=	-DNO_PF=1

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/dhcpd.conf|${PREFIX}/etc/dhcpd.conf|" \
		${WRKSRC}/dhcpd.[h8]

post-install:
	${INSTALL_DATA} ${WRKSRC}/dhcpd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpd.conf.sample

.include <bsd.port.mk>
