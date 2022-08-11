PORTNAME=	poptop
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	SF/${PORTNAME}/pptpd/pptpd-${PORTVERSION} \
		SAMBA/ppp:pppd
DISTFILES=	pptpd-${PORTVERSION}${EXTRACT_SUFX} \
		${PPPD_DISTNAME}${EXTRACT_SUFX}:pppd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows 9x compatible PPTP (VPN) server

LICENSE=	GPLv2
LICENSE_DISTFILES=	pptpd-${PORTVERSION}${EXTRACT_SUFX}

OPTIONS_DEFINE=	KERNPPP
KERNPPP_DESC=	Use kernel-space PPP

WRKSRC=		${WRKDIR}/pptpd-${PORTVERSION}

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap

USE_RC_SUBR=	pptpd

CFLAGS+=	-I${WRKDIR}/${PPPD_DISTNAME}

KERNPPP_CONFIGURE_OFF=	--with-bsdppp

PPPD_DISTNAME=	ppp-2.4.5

.include <bsd.port.options.mk>

post-patch:
.for i in pptpctrl.c pptpd.8 pptpd.conf.5
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install:
	(cd ${WRKSRC}/samples && ${INSTALL_DATA} pptpd.conf \
		${STAGEDIR}${PREFIX}/etc/pptpd.conf.sample)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pptpd/pptpd-logwtmp.so

.include <bsd.port.mk>
