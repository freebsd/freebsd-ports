# New ports collection makefile for:	dansguardian
# Date created:				March 26, 2002
# Whom:					Freddie Cash <fcash@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.2.7.1
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	DansGuardian-2.2.7-1.source

MAINTAINER=	fcash@bigfoot.com

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid24:install \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13:install

WRKSRC=		${WRKDIR}/DansGuardian-2.2.7
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=/sbin/ \
		--sysconfdir=/etc/dansguardian/ \
		--sysvdir=/etc/rc.d/ \
		--mandir=/man/ \
		--logdir=/squid/logs/ \
		--cgidir=/www/cgi-bin/ \
		--piddir=/var/run/

DG_URL=		http://dansguardian.org/index.php?page=copyright2

.if defined(WITHOUT_PICS)
CONFIGURE_ARGS+= --without-pics-filter
.endif

MAN8=		dansguardian.8
MANCOMPRESSED=	no

NO_CDROM=	"Commercial download is restricted.  Check ${DG_URL} for more info"
NO_PACKAGE=	"Redistribution is restricted.  Check ${DG_URL} for more info"

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then         \
	${ECHO} "";							 \
	${ECHO} "   Commercial downloading is restricted.  Please read"; \
	${ECHO} "   the licensing info at ${DG_URL}"; \
	${ECHO} "";							 \
	${ECHO} "   The DansGuardian sources must be fetched manually."; \
	${ECHO} "   Download ${DISTNAME}${EXTRACT_SUFX} and place it in";\
	${ECHO} "   ${DISTDIR} then run make install.";\
	${ECHO} "";\
	${FALSE};\
	fi

.include <bsd.port.mk>
