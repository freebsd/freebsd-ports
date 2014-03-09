# Created by: Dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	fixbuf:${PORTSDIR}/net/libfixbuf \
		pcre.3:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USES=		pkgconfig perl5
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
CONFIOGURE_ARGS+=	--disable-doxygen

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--with-dag=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
