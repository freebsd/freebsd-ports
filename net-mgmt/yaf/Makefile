# New ports collection makefile for: yaf
# Date created:		2009-06-29
# Whom:			Dikshie <dikshie@sfc.wide.ad.jp>
#
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	fixbuf:${PORTSDIR}/net/libfixbuf \
		pcre.1:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
USE_PERL5=	yes
MAKE_JOBS_SAFE=	yes
CONFIOGURE_ARGS+=	--disable-doxygen

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		airdaemon.1 applabel.1 \
		filedaemon.1 yaf.1 yafdpi.1 yafscii.1

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--with-dag=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
