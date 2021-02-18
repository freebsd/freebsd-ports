# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	netustad
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based admin tool that manages network services

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: adminpasswd
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: adminpasswd

USES=		gettext
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SSL NLS DOCS
OPTIONS_DEFAULT=SSL
SSL_DESC=	Use netUstad with SSL support

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	ssl

NLS_CONFIGURE_WITH=	nls

post-patch-DOCS-off:
	${REINPLACE_CMD} "s/^install-data-am:.*/install-data-am:/" ${WRKSRC}/Makefile.in

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/netustad.conf-dist ${STAGEDIR}${ETCDIR}/netustad.conf.sample

.include <bsd.port.mk>
