# $FreeBSD$

PORTNAME=	mpd-l2tp-ipv6pd-client
PORTVERSION=	20150430
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Sample implementation set of "L2TP-IPv6PD" client using mpd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	mpd5:net/mpd5
RUN_DEPENDS=	dhcp6ctl:net/dhcp6 \
		mpd5:net/mpd5

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME}-setup \
		${TEMPLATE_FILES:C,^,${DATADIR_REL}/,g}

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message \
		setup

TEMPLATE_FILES=	dhcp6c.conf.in.in \
		dhcp6c_pd.sh.in \
		linkdown.sh.in \
		linkup.sh.in \
		mpd.conf.in \
		mpd.in \
		mpd.secret.in \
		rtadvd.conf.in

do-install:
	@${INSTALL} ${WRKDIR}/setup ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}-setup
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${TEMPLATE_FILES}
	@${INSTALL_DATA} ${FILESDIR}/${f} ${STAGEDIR}${DATADIR}/${f}
.endfor

setup:
	@${PREFIX}/sbin/${PORTNAME}-setup

.include <bsd.port.mk>
