# New ports collection makefile for:	dansguardian
# Date created:				April 02, 2002
# Whom:					Freddie Cash <fcash@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.4.6.5
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	DansGuardian-${PORTVERSION:R}-${PORTVERSION:E}.source

MAINTAINER=	fcash@bigfoot.com

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid24:install \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13:install

WRKSRC=		${WRKDIR}/DansGuardian-${PORTVERSION:R}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=/sbin/ \
		--sysconfdir=/etc/dansguardian/ \
		--sysvdir=/etc/rc.d/ \
		--mandir=/man/ \
		--logdir=/var/log/ \
		--cgidir=/www/cgi-bin/ \
		--piddir=/var/run/

DG_URL=		http://dansguardian.org/index.php?page=copyright2

MAN8=		dansguardian.8

NO_CDROM=	"Commercial download is restricted.  Check ${DG_URL} for more info"
NO_PACKAGE=	"Redistribution is restricted.  Check ${DG_URL} for more info"

.include <bsd.port.pre.mk>

.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
FORBIDDEN="Commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make"
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
