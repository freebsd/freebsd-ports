# New ports collection makefile for:   gateway6
# Date created:        11 Jul 2007
# Whom:                Michael Scholz (mike@fth-devel.net)
#
# $FreeBSD$
#

PORTNAME=	gateway6
PORTVERSION=	5.0
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.fth-devel.net/pub/freenet6/
MASTER_SITES+=	http://www.go6.net/4105/file.asp?file_id=142/
DISTNAME=	gw6c-5_0-RELEASE-src

MAINTAINER=	mike@fth-devel.net
COMMENT=	Gateway6 Tunnel Setup Protocol Client - Free IPv6 tunnel

USE_RC_SUBR=	gateway6.sh
WRKSRC=		${WRKDIR}/tspc-advanced

MAN8=		gw6c.8
MAN5=		gw6c.conf.5

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	gateway6.sh pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=		this program might not be working on FreeBSD version below 4.0
.endif
.if ${OSVERSION} > 500000
EXTRA_PATCHES=	${FILESDIR}/patch5-template.freebsd.sh
.endif

MAKE_ARGS=	target=freebsd installdir=${PREFIX}
GW6C_DATA=	CLIENT-LICENSE.TXT GUI-LICENSE.TXT INSTALL README

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gw6c ${PREFIX}/bin/gw6c
	@${INSTALL_MAN} ${WRKSRC}/man/man8/gw6c.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/man/man5/gw6c.conf.5 ${PREFIX}/man/man5
	@${INSTALL_SCRIPT} ${WRKSRC}/template/checktunnel.sh ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/template/freebsd.sh ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/gw6c.conf.sample ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKDIR}/HEX_DC_0005_Gateway6_Client_Guide.pdf ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/HEX_DC_0007_Gateway6_Client_Release_Notes.pdf ${DATADIR}

.for f in ${GW6C_DATA}
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor

post-install:
	@if [ ! -f ${PREFIX}/etc/orbit.conf ]; then \
		${CP} -p ${PREFIX}/etc/gw6c.conf.sample ${PREFIX}/etc/gw6c.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/installdir/bin|${PREFIX}/etc|g" \
		${WRKSRC}/man/man8/gw6c.8

	@${REINPLACE_CMD} \
		-e "s|/usr/local/gw6c|${PREFIX}|g" \
		-e "s|/install/dir/bin/gw6c.conf.sample|${EXAMPLESDIR}/gw6c.conf.sample|g" \
		-e "s|/install/dir/bin/gw6c.conf|${PREFIX}/etc/gw6c.conf|g" \
		-e "s|template=linux|template=freebsd|g" \
		${WRKSRC}/man/man5/gw6c.conf.5

.include <bsd.port.post.mk>
