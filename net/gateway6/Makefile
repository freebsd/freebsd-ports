# New ports collection makefile for:   gateway6
# Date created:        11 Jul 2007
# Whom:                Michael Scholz (mike@fth-devel.net)
#
# $FreeBSD$
#

PORTNAME=	gateway6
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://go6.net/4105/file.asp?file_id=166&foo=/
MASTER_SITES+=	http://go6.net/4105/file.asp?file_id=166&
DISTNAME=	gw6c-6_0-RELEASE-src

MAINTAINER=	mike@fth-devel.net
COMMENT=	Gateway6 Tunnel Setup Protocol Client - Free IPv6 tunnel

CONFLICTS=	freenet6-[0-9]*

USE_RC_SUBR=	gateway6
WRKSRC=		${WRKDIR}/gw6c-6_0_1
ETCDIR=		${PREFIX}/etc

MAN8=		gw6c.8
MAN5=		gw6c.conf.5
GW6C_DATA=	\
		CLIENT-LICENSE.TXT \
		INSTALL \
		README \
		HEX_DC_0005_Gateway6_Client_Guide.pdf \
		HEX_DC_0007_Gateway6_Client_Release_Notes.pdf

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	gateway6.sh pkg-message

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_UNSAFE=yes
MAKE_ARGS=	target=freebsd installdir=${PREFIX}

.include <bsd.port.pre.mk>

post-install:
.for f in ${GW6C_DATA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/usr/local/etc/gw6|${PREFIX}|g" \
		-e "s|gw6c.conf|${ETCDIR}/gw6c.conf|g" \
		${WRKSRC}/tspc-advanced/platform/freebsd/tsp_local.c
	@${REINPLACE_CMD} \
		-e 's|"template"|"share/gateway6"|g' \
		${WRKSRC}/tspc-advanced/src/lib/config.c
	@${REINPLACE_CMD} \
		-e "s|gifconfig=/usr/sbin/gifconfig|gifconfig=/sbin/ifconfig|g" \
		${WRKSRC}/tspc-advanced/template/freebsd.sh
	@${REINPLACE_CMD} \
		-e "s|/installdir/bin|${ETCDIR}|g" \
		${WRKSRC}/tspc-advanced/man/man8/gw6c.8

	@${REINPLACE_CMD} \
		-e "s|/usr/local/gw6c|${PREFIX}|g" \
		-e "s|/install/dir/bin/gw6c.conf.sample|${ETCDIR}/gw6c.conf.sample|g" \
		-e "s|/install/dir/bin/gw6c.conf|${ETCDIR}/gw6c.conf|g" \
		-e "s|template=linux|template=freebsd|g" \
		${WRKSRC}/tspc-advanced/man/man5/gw6c.conf.5

.include <bsd.port.post.mk>
