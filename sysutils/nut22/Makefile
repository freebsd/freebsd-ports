# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	0.45.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.exploits.org/nut/release/

MAINTAINER=	DougB@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/nut \
		--localstatedir=/var/db/nut \
		--with-modelpath=${PREFIX}/libexec/nut \
		--with-statepath=/var/db/nut \
		--with-altpidpath=/var/db/nut \
		--with-pidpath=/var/db/nut

MAN5=		ups.conf.5 upsd.conf.5 upsd.users.5 upsmon.conf.5 \
		upssched.conf.5
MAN8=		apcsmart.8 belkin.8 bestups.8 fentonups.8 nutupsdrv.8 \
		powercom.8 upsc.8 upscmd.8 upsct.8 upsct2.8 upsd.8 \
		upsdrvctl.8 upslog.8 upsmon.8 upssched.8

ALL_TARGET=	all

.if defined(CGI)
LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
CONFIGURE_ARGS+=--with-cgipath=${PREFIX}/${CGIDIR}/nut
ALL_TARGET+=	cgi
PLIST_SUB+=	CGIFILES="${CGIDIR}/nut/"
PLIST_SUB+=	CGIDIRRM="@dirrm ${CGIDIR}/nut"
.else
PLIST_SUB+=	CGIFILES="@comment "
PLIST_SUB+=	CGIDIRRM="@comment "
.endif

pre-fetch:
.if !defined(CGI)
	@${ECHO_MSG} "Type \"make CGI=yes\" if you want to build CGI scripts."
.endif

pre-install:
	@${MKDIR} ${PREFIX}/libexec/nut
	@${MKDIR} /var/db/nut
	@${CHOWN} uucp /var/db/nut

NDOCDIR=	${PREFIX}/share/doc/nut

post-install:
	@${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" \
		${WRKSRC}/scripts/FreeBSD/upsd.sh.sample \
		>${PREFIX}/etc/rc.d/nut.sh.sample
	@${CHMOD} 0755 ${PREFIX}/etc/rc.d/nut.sh.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ups.conf \
		${PREFIX}/etc/nut/ups.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${NDOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NDOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Changes.trust ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${NDOCDIR}
.endif
.if defined(CGI)
	@${MKDIR} ${PREFIX}/${CGIDIR}/nut
	${INSTALL_DATA} ${WRKSRC}/clients/*.cgi ${PREFIX}/${CGIDIR}/nut
.endif

.include <bsd.port.mk>
