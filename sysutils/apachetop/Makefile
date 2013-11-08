# Created by: Sebastian Yepes F. <esn@x123.info>
# $FreeBSD$

PORTNAME=	apachetop
PORTVERSION=	0.12.6
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webta.org/apachetop/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache RealTime log stats

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	ADNS FAM PCRE
ADNS_DESC=	Asynchronous-capable DNS support

ADNS_LIB_DEPENDS=	libadns.so:${PORTSDIR}/dns/adns
ADNS_CONFIGURE_ON=	--with-adns=${LOCALBASE}

FAM_LIB_DEPENDS=	libfam.so:${PORTSDIR}/devel/fam
FAM_CONFIGURE_ON=	--with-fam=${LOCALBASE}

PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_COFNIGURE_ON=	--with-pcre=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -E -e 's,struct (circle_struct),\1,g' \
		${WRKSRC}/src/hits_circle.*
	@${REINPLACE_CMD} -E -e 's,enum (adns_queryflags),\1,g' \
		${WRKSRC}/src/log.*
	@cd ${WRKSRC} && ${TOUCH} -r configure.ac aclocal.m4 stamp-h.in

.include <bsd.port.mk>
