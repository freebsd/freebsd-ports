# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	1.2.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/ \
		http://www.outloud.org/ipa/ \
		http://ipa.it-ss.be/

MAINTAINER=	simon@simon.org.ua

NO_PACKAGE=	"Needs to be built uniquely for each host"
ALL_TARGET=	FreeBSD
.ifdef(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
.endif

MAN5=		ipa.5 ipa.conf.5
MAN8=		ipa.8 ipastat.8
MANLANG=	"" ru_RU.KOI8-R

.include <bsd.port.pre.mk>

pre-everything:
	@${ECHO_MSG} "-------------------------------------------------------------------"
.if !defined(WITHOUT_IPFW)
	@${ECHO_MSG} "o You can remove IPv4 Firewall support by defining WITHOUT_IPFW"
.endif
.if !defined(WITHOUT_IP6FW) && ${OSVERSION} >= 420001
	@${ECHO_MSG} "o You can remove IPv6 Firewall support by defining WITHOUT_IP6FW"
.endif
.if !defined(WITHOUT_IPFIL)
	@${ECHO_MSG} "o You can remove IP Filter support by defining WITHOUT_IPFIL"
.endif
.if !defined(WITHOUT_IP6FW) && !defined(WITH_IP6FW) && ${OSVERSION} >= 400000 && ${OSVERSION} < 420001
	@${ECHO_MSG} "o You can add IPv6 Firewall support by defining WITH_IP6FW,"
	@${ECHO_MSG} "  this support will be probably broken on your system (see the"
	@${ECHO_MSG} "  ${WRKSRC}/INSTALL file for more information)"
.endif
.if !defined(IPFW2) && !defined(WITHOUT_IPFW) && ${OSVERSION} >= 460100 && ${OSVERSION} < 500038
	@${ECHO_MSG} "o You can add IPFW2 support by defining IPFW2"
.endif
	@${ECHO_MSG} "-------------------------------------------------------------------"

.include <bsd.port.post.mk>
