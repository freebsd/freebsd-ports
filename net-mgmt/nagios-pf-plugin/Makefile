PORTNAME=	nagios-pf-plugin
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios plugin for checking PF
WWW=		https://github.com/kian/nagios-pf-plugin/

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
LIB_DEPENDS=	libpfctl.so:net/libpfctl

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpfctl
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	kian
GH_TAGNAME=	2aba423

PLIST_FILES=	libexec/nagios/check_pf
SUB_FILES=	pkg-message

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-check_pf.c
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-check_pf_15.c
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
