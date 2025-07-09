PORTNAME=	ipp-usb
DISTVERSION=	0.9.24
PORTREVISION=	5
CATEGORIES=	print

MAINTAINER=	chuanwei.foo@hotmail.com
COMMENT=	Daemon for IPP over USB printer support
WWW=		https://github.com/OpenPrinting/ipp-usb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavahi-common.so:net/avahi-app

USES=		gmake go:modules pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	OpenPrinting
GH_TUPLE=	OpenPrinting:goipp:v1.1.0:openprinting_goipp/vendor/github.com/OpenPrinting/goipp

USE_RC_SUBR=	ipp-usb

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/ipp-usb|${DATADIR}|g' \
		-e 's|/etc/ipp-usb|${ETCDIR}|g' \
		${WRKSRC}/paths.go

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/ipp-usb ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${ETCDIR}/quirks/
	${INSTALL_DATA} ${WRKSRC}/ipp-usb.conf \
		${STAGEDIR}${ETCDIR}/ipp-usb.conf.sample
	${INSTALL_MAN} ${WRKSRC}/ipp-usb.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	(cd ${WRKSRC}/ipp-usb-quirks/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/quirks/)

.include <bsd.port.mk>
