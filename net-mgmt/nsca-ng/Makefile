# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	nsca-ng
PORTVERSION=	1.0
#PORTREVISION=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.nsca-ng.org/download/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	NSCA alternative

LIB_DEPENDS=	confuse:${PORTSDIR}/devel/libconfuse \
				ev:${PORTSDIR}/devel/libev

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${LOCALBASE}/man \
					--with-confuse=${LOCALBASE} \
					--with-ev=${LOCALBASE} \
					--with-openssl=${OPENSSLBASE}
USE_OPENSSL=	yes
USE_OPENSSL_PORT=	yes
MANCOMPRESSED=	no

# TODO
# - DOCS
.if defined(_BUILDING_NSCA_CLIENT)
CONFLICTS=	nsca-client-[0-9]*
CONFIGURE_ARGS+=	--disable-server --enable-client
MAN5+=	send_nsca.cfg.5
MAN8+=	send_nsca.8
NSCA_NG_CONF=	send_nsca.cfg
PLIST_SUB+=	SERVER="@comment "
PLIST_SUB+=	CLIENT=""
.else
CONFIGURE_ARGS+=	--enable-server --disable-client
USE_RC_SUBR=	nsca-ng
MAN5+=	nsca-ng.cfg.5
MAN8+=	nsca-ng.8
NSCA_NG_CONF=	nsca-ng.cfg
PLIST_SUB+=	CLIENT="@comment "
PLIST_SUB+=	SERVER=""
.endif

post-install:
.for M in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${M:S/.5$//}.man ${MANPREFIX}/man/man5/${M}
.endfor
.for M in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${M:S/.8$//}.man ${MANPREFIX}/man/man8/${M}
.endfor
.for F in ${NSCA_NG_CONF}
	${INSTALL_DATA} ${WRKSRC}/etc/${F} ${PREFIX}/etc/${F}-dist
.endfor

.include <bsd.port.mk>
